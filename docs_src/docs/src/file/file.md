# file
## Abstract
The ```file``` class is used to manage file pointers.  
```file``` クラスは，file ポインタの管理に利用します．

## Header file
```cpp
namespace sstd{ class file; }
class sstd::file{
private:
public:
    FILE* fp;
    file(){ fp=0; }
//  file(const char*& fileName, const char*& mode){ fopen(&fp, fileName, mode); } // コンストラクタでは，fopen の失敗を検知できないので，これは実装しないように!!!
    ~file(){ if(fp!=0){ ::fclose(fp); } }
    
    bool fopen(const char* fileName, const char* mode);
    bool fopen(const std::string& fileName, const char* mode);
    bool fclose();
    size_t fread(void* ptr, const size_t& size, const size_t& nmemb);
    size_t fwrite(const void* ptr, const size_t& size, const size_t& nmemb);
    int fseek(const long& offset, const int& whence);
    long ftell();

    size_t fsize();
};
```

## Usage
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'abc\ndef' > ./tmp/example.txt");
    
    sstd::file fp;
    if(!fp.fopen("./tmp/example.txt", "rb")){ sstd::pdbg("ERROR: fopen was failed.\n"); return -1; }
    size_t size = fp.fsize();
    std::vector<char> raw(size+1, 0);
    if(fp.fread((uchar*)&raw[0], sizeof(char), size)!=size){ sstd::pdbg("ERROR: fread was failed.\n"); return -1; }
    
    printf("&raw[0] = %s\n", &raw[0]);
    
    sstd::rm("./tmp");
    return 0; // fp is automatically closed by RAII.
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/file.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/file.cpp)
- Header: [sstd/src/file/file.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/file.hpp)
- Test: [test/file/file.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/file.hpp)
  (Not implemented yet)

