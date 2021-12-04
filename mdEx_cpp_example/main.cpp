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

std::string cpp2exe(const std::string& exe_path, const std::string& cpp_path){
    std::string CXX = R"(g++)";
    std::string CFLAG;
    CFLAG += R"( -L./sstd/lib -I./sstd/include -lsstd)"; // sstd
    CFLAG += R"( -std=c++11)";
    CFLAG += R"( -Wall)";
    CFLAG += R"( -O3)";
    std::string cmd = sstd::ssprintf("%s -o %s %s %s", CXX.c_str(), exe_path.c_str(), cpp_path.c_str(), CFLAG.c_str());
    
    return sstd::system_stdout_stderr(cmd); // compile with g++
}

std::string cpp2out(const std::string& tmpDir, const std::string& cpp_path){
    std::string ret;
    
    // compile with g++
    std::string fileName = sstd::getFileName_withoutExtension(cpp_path.c_str()) + ".exe";
    std::string exe_path = tmpDir + '/' + fileName;
    ret += cpp2exe(exe_path, cpp_path);
    if(ret.size()!=0){
        printf("\u001b[31m"); // set output red
        printf("Compile ERROR or WARNING: "); // set output red
        printf("%s\n", ret.c_str());
        printf("\u001b[0m"); // reset color
    }
    
    // get output
    sstd::system( sstd::ssprintf("cp -r ./sstd ./%s", tmpDir.c_str()) );
    std::string cmd = sstd::ssprintf("cd %s; ./%s", tmpDir.c_str(), fileName.c_str());
    ret += sstd::system_stdout_stderr(cmd); // running exe
    
    return ret;
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
	printf("Compile ERROR or WARNING: "); // set output red
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
    
    std::string cpp_out;
    
    uint l = vStrIn.size(); // num of lines
    for(uint i=0; i<l; ++i){
        vStrOut <<= vStrIn[i];
        sstd::strip_ow(vStrIn[i]);
        
        if(vStrIn[i] == "#mdEx: cpp example (in)"){
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
            std::string tmpDir_exe = tmpDir+'/'+file_name;
            sstd::mkdir(tmpDir_exe);
            
            std::string cpp_path = tmpDir+'/'+file_name+'/'+file_name;
            sstd::write(cpp_path, cpp_code);
            cpp_out = cpp2out(tmpDir_exe, cpp_path); // cpp_file to output
	    runTimeErrCheck(cpp_out);
            
            sstd::rm(tmpDir_exe);
            
        }else if(vStrIn[i] == "#mdEx: cpp example (out)"){
            vStrOut.pop_back(); // rm "#mdEx: cpp example (in)"
            vStrOut <<= cpp_out;
        }
    }
    std::string strOut = vStr2str_n(vStrOut);
    if(sstd::write(path_out, strOut)!=strOut.size()){ sstd::pdbg("ERROR: sstd::write() was failed.\n"); return false; }
    
    return 0;
}
