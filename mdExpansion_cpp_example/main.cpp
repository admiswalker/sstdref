#include <sstream>
#include <sstd/sstd.hpp>

std::string vStr2str_n(const std::vector<std::string>& vStr){
    std::string s;
    for(uint i=0; i<vStr.size(); ++i){
        s += vStr[i]+'\n';
    }
    return s;
}

bool sstd__save2file(const std::string& tmpFile, const std::string& s){
    sstd::file fp;
    if(! fp.fopen(tmpFile, "wb") ){ sstd::pdbg("ERROR: fopen was failed.\n"); return false; }
    
    size_t w_size = fp.fwrite(&s[0], sizeof(char), s.size());
    if(w_size != s.size()){ sstd::pdbg("ERROR: fopen was failed.\n"); return false; }
    
    return true;
}

std::string sstd__system_stdout_stderr(const std::string& cmd){
    std::string ret;
    
    FILE* fp;
    std::string cmd_stdout_stderr = cmd + R"( 2>&1)";
    if((fp = popen(cmd_stdout_stderr.c_str(), "r"))==NULL){ sstd::pdbg("ERROR: popen was failed.\n"); return ""; }
    
    char buf[1024];
    while(fgets(buf, 1024, fp) != NULL){ ret+=buf; }
    
    pclose(fp);
    return ret;
}

std::vector<std::string> cpp2out(const std::string& tmpFile, const std::vector<std::string>& vCppCode){
    std::vector<std::string> vStr_ret;
    
    // vCppCode to file
    std::string s = vStr2str_n(vCppCode);
    sstd__save2file(tmpFile, s);
    
    // compile with GCC
    std::string CXX = R"(g++)";
    std::string CFLAG;
    CFLAG += R"( -L./sstd/lib -I./sstd/include -lsstd)"; // sstd
    CFLAG += R"( -L./googletest-master/build/lib -I./googletest-master/googletest/include -lgtest -pthread)"; // google test
    CFLAG += R"( -std=c++11)";
    CFLAG += R"( -Wall)";
    CFLAG += R"( -O3)";
    std::string savePath = sstd::getPath(tmpFile.c_str()) + sstd::getFileName_withoutExtension(tmpFile.c_str());
    std::string cmd = sstd::ssprintf("%s -o %s.exe %s %s", CXX.c_str(), savePath.c_str(), tmpFile.c_str(), CFLAG.c_str());
    sstd::printn(cmd);
    
    // run command
    std::string ret = sstd__system_stdout_stderr(cmd);
    sstd::printn(ret);
    
    // get output
    
//    sstd::rm(tmpFile);
    return vStr_ret;
}

// gcc -o ./tmp/in.md_11.exe ./tmp/in.md_11.cpp -L./sstd/lib -I./sstd/include -lsstd -std=c++14 -Wall -O3


int main(int argc, char *argv[]){
    if(argc != 1+2){ sstd::pdbg("ERROR: input args != 2.\n"); return -1; }
    std::string path_out = argv[1];
    std::string path_in  = argv[2];
    
    std::string strIn = sstd::readAll(path_in);
    std::vector<std::string> vStrIn = sstd::splitByLine(strIn);
    std::vector<std::string> vStrOut;
    
    std::string tmpDir = "./tmp";
    sstd::mkdir(tmpDir);
    
    uint l = vStrIn.size(); // num of lines
    for(uint i=0; i<l; ++i){
        vStrOut <<= vStrIn[i];
        sstd::strip_ow(vStrIn[i]);
        std::vector<std::string> vCppCode;
        
        if(vStrIn[i] == "#mdEx: cpp example (in)"){
            ++i;
            vStrOut.pop_back();
            
            while(vStrIn[i]!="```" && i<l){
                vCppCode <<= vStrIn[i];
                vStrOut  <<= vStrIn[i];
                ++i;
            }
            vStrOut <<= vStrIn[i]; // add "```"
            sstd::printn(vCppCode);
            
            vStrOut <<= cpp2out(tmpDir+'/'+path_in+'_'+sstd::ssprintf("%d",i)+".cpp", vCppCode);
            sstd::printn(vStrOut);
            
        }else if(vStrIn[i] == "#mdEx: cpp example (out)"){
            sstd::printn(vStrIn[i]);
        }
    }
    
	return 0;
}
