# rm
## Abstract
```rm.cpp``` / ```rm.hpp``` contains the processing related to deletion.  
```rm.cpp``` / ```rm.hpp``` にはディレクトリ削除に関する処理を収録します．

## Header file
```c++
namespace sstd{
    struct pathAndType{
        std::string path;
        char type;        // 'f': file, 'd': directory
    };
    
    bool unlink(const char*        pPath); // delete file
    bool unlink(const std::string&  path); // delete file

    bool rmdir (const char*        pPath); // delete empty directory
    bool rmdir (const std::string&  path); // delete empty directory

    bool getAllPath(std::vector<struct sstd::pathAndType>& ret, const char* pPath); // get all path in the directory
    bool getAllPath(std::vector<std::string>& ret, const char* pPath); // get all path in the directory
    bool getAllFile(std::vector<std::string>& ret, const char* pPath); // get all file path in the directory
    bool getAllDir (std::vector<std::string>& ret, const char* pPath); // get all directory path in the directory
    bool rm    (const char*        pPath); // delete all under the pPath
    bool rm    (const std::string&  path); // delete all under the path
}
```

## Usage
### Removing directories recursively (ディレクトリの再帰的な削除)
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    printf("--- mkdir ---\n"); fflush(stdout);
    sstd::mkdir("./tmp/a/b/c");
    sstd::system("tree ./tmp");
    printf("\n\n");

    printf("--- rm ---\n"); fflush(stdout);
    sstd::rm("./tmp");
    sstd::system("tree ./tmp");
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/rm.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/rm.cpp)
- Header: [sstd/src/rm.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/rm.hpp)
- Test: [test/rm.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/rm.hpp)
  (Not implemented yet)

