# file
## Abstract
The `file` class is used to manage file pointers.  
`file` クラスは，file ポインタの管理に利用します．

## Header file
```cpp
namespace sstd{ class file; }
class sstd::file{
private:
    FILE* fp;
    int type; // 0: fopen(), 1: popen().
    
public:
    file();
    ~file();
    
    bool fopen(const        char* fileName, const char* mode);
    bool fopen(const std::string& fileName, const char* mode);
    bool popen(const        char* fileName, const char* mode);
    bool popen(const std::string& fileName, const char* mode);
    bool close();
    
    char*  fgets (char* s, int size);
    size_t fread (void* ptr, const size_t& size, const size_t& nmemb);
    template <typename... Args>
    int    fscanf(const char* format, Args const&... args){ return ::fscanf(this->fp, format, args...); }
    int    fseek (const long& offset, const int& whence);
    size_t fsize();
    long   ftell();
    size_t fwrite(const void* ptr, const size_t& size, const size_t& nmemb);
};
```

## Usage
- <u>**example.txt**</u>
```
#mdEx: cpp example (in:attachment:example.txt)
abc
def
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::file fp;
    if(!fp.fopen("example.txt", "rb")){ sstd::pdbg("ERROR: fopen was failed.\n"); return -1; }
    size_t size = fp.fsize();
    std::vector<char> raw(size+1, 0);
    if(fp.fread((uchar*)&raw[0], sizeof(char), size)!=size){ sstd::pdbg("ERROR: fread was failed.\n"); return -1; }
    
    printf("&raw[0] = %s\n", &raw[0]);
    
    return 0; // fp is automatically closed by RAII.
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/file.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/file.cpp)
- Header: [sstd/src/file/file.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/file.hpp)
- Test: [test/src_test/file/file.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/file.cpp)

