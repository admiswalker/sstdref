#include <sstream>
#include <regex>
#include <sstd/sstd.hpp>


std::string vStr2str_n(const std::vector<std::string>& vStr){
    std::string s;
    for(uint i=0; i<vStr.size(); ++i){
        s += vStr[i]+'\n';
    }
    return s;
}

void gen_attachment_files(const std::string& dir_path, const std::vector<std::string>& v_filename, const std::vector<std::string>& v_txt){
    uint l = v_filename.size();
    for(uint i=0; i<l; ++i){
	std::string filepath = dir_path+'/'+v_filename[i];
	sstd::write(filepath, v_txt[i]);
    }
}

void cpp2exe(const std::string& exe_path, const std::string& cpp_path){
    std::string CXX = R"(g++)";
    std::string CFLAG;
    CFLAG += R"( -L./sstd/lib -I./sstd/include -lsstd)"; // sstd
    CFLAG += R"( -std=c++2a)"; // C++ 20
    CFLAG += R"( -Wall)";
    CFLAG += R"( -O3)";
    std::string cmd = sstd::ssprintf("%s -o %s %s %s", CXX.c_str(), exe_path.c_str(), cpp_path.c_str(), CFLAG.c_str());
    std::string res = sstd::system_stdout_stderr(cmd); // compile with g++
    if(res.size()!=0){
        printf("\u001b[31m"); // set output red
        printf("Compile ERROR or WARNING: "); // set output red
        printf("%s\n", res.c_str());
        printf("\u001b[0m"); // reset color
    }
    return;
}

std::string cpp2out(const std::string& tmpDir, const std::string& fileName, const std::string& args){
    sstd::system( sstd::ssprintf("cp -r ./sstd ./%s", tmpDir.c_str()) );
    std::string cmd = sstd::ssprintf("cd %s; ./%s %s", tmpDir.c_str(), fileName.c_str(), args.c_str());
    return sstd::system_stdout_stderr(cmd); // running exe
}


bool errCheck_Cpp(const std::string& s){
    return false;
}
bool errCheck_PythonERRORsAndWarnings(const std::string& s){
    bool TF = false;
//  TF ^= sstd::strmatch(s, "*ModuleNotFoundError*");
//  TF ^= sstd::strmatch(s, "*ImportError*");
    TF ^= sstd::strmatch(s, "*Error*");
    TF ^= sstd::strmatch(s, "*Warning*");
    return TF;
}
void runTimeErrCheck(const std::string& s){
    bool TF = false;
    TF ^= errCheck_Cpp(s);
    TF ^= errCheck_PythonERRORsAndWarnings(s);
    
    if(TF){
	printf("\u001b[31m"); // set output red
	printf("Runtime ERROR or WARNING: "); // set output red
	printf("%s\n", s.c_str());
	printf("\u001b[0m"); // reset color
    }
}

int main(int argc, char *argv[]){
    if(argc != 1+3){ sstd::pdbg("ERROR: input args != 3.\n"); return -1; }
    std::string tmpDir   = argv[1];
    std::string path_in  = argv[2];
    std::string path_out = argv[3];
    
    std::string strIn = sstd::read(path_in);
    std::vector<std::string> vStrIn = sstd::splitByLine(strIn);
    std::vector<std::string> vStrOut;

    std::string tmpDir_exe;
    std::string cpp_path;
    
    std::vector<std::string> vAttachment_filename;
    std::vector<std::string> vAttachment_txt;
    
    const uint l = vStrIn.size(); // num of lines
    for(uint i=0; i<l; ++i){
        vStrOut <<= vStrIn[i];
        sstd::strip_ow(vStrIn[i]);
	
	std::string filename;
        if(sstd::strmatch_getWC(vStrIn[i], "#mdEx: cpp example (in:attachment:*)", filename)){
            ++i;
            vStrOut.pop_back(); // rm "#mdEx: cpp example (in:attachment)"
            
            std::string attachment;
            while(vStrIn[i]!="```" && i<l){
                vStrOut <<= vStrIn[i];
                attachment += vStrIn[i] + '\n';
                ++i;
            }
            vStrOut <<= vStrIn[i]; // add "```"
            
            vAttachment_filename <<= filename;
            vAttachment_txt      <<= attachment;
	    
	}else if(vStrIn[i] == "#mdEx: cpp example (in)"){
            ++i;
            vStrOut.pop_back(); // rm "#mdEx: cpp example (in)"
            
            std::string cpp_code;
            while(vStrIn[i]!="```" && i<l){
                vStrOut <<= vStrIn[i];
                cpp_code += vStrIn[i] + '\n';
                ++i;
            }
            vStrOut <<= vStrIn[i]; // add "```"
            
            // vCppCode to cpp_file
            std::string file_name = std::regex_replace(path_in.c_str(), std::regex("/"), "_")+'_'+sstd::ssprintf("%d",i)+".cpp";
            tmpDir_exe = tmpDir+'/'+file_name;
            sstd::mkdir(tmpDir_exe);
            
	    gen_attachment_files(tmpDir_exe, vAttachment_filename, vAttachment_txt);
            
            cpp_path = tmpDir+'/'+file_name+"/a.cpp";
            sstd::write(cpp_path, cpp_code);
            
        }else if(vStrIn[i] == "#mdEx: cpp example (out)"){
            ++i;
            vStrOut.pop_back(); // rm "#mdEx: cpp example (in)"

            std::vector<std::string> vCmdArgs;
            while(vStrIn[i]!="```" && i<l){
                vCmdArgs <<= vStrIn[i];
                ++i;
            }
            
            std::string fileName = "a.out";
            std::string exe_path = tmpDir_exe + '/' + fileName;
            cpp2exe(exe_path, cpp_path); // compile with g++
            sstd::printn_all(vCmdArgs);
            std::string cpp_out;
            if(vCmdArgs.size()==0){
                cpp_out += cpp2out(tmpDir_exe, fileName, ""); // execute compiled binary
            }
            for(uint i=0; i<vCmdArgs.size(); ++i){
                cpp_out += vCmdArgs[i] + '\n';
                cpp_out += cpp2out(tmpDir_exe, fileName, std::regex_replace(vCmdArgs[i], std::regex("\\$ ./a.out"), "")); // execute compiled binary
            }
	    runTimeErrCheck(cpp_out);
            sstd::rm(tmpDir_exe);
            
            vStrOut <<= cpp_out;
            vStrOut <<= vStrIn[i]; // add "```"
            
	    vAttachment_filename.clear();
	    vAttachment_txt.clear();
        }
    }
    std::string strOut = vStr2str_n(vStrOut);
    if(sstd::write(path_out, strOut)!=strOut.size()){ sstd::pdbg("ERROR: sstd::write() was failed.\n"); return false; }
    
    return 0;
}
