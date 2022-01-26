# path
## Abstract
`path.hpp` contains functions for path editing.  
`path.hpp` はパス編集用の関数を収録します．

## Header file
```cpp
namespace sstd{
    std::string  getPath                     (const char* pPath);
    std::string  getPath_owWC                (const char* pPath); // _owWC: without wild card
    
    std::string  getDirName                  (const char* pPath);
    uint         getDirName_begin_idx        (const char* pPath);
    uint         getDirName_end_idx          (const char* pPath);
    uint         getDirName_end_idx_owWC     (const char* pPath); // _owWC: without wild card
    
           char* getFileName                 (const char* pPath);
    std::string  getFileName_withoutExtension(const char* pPath);
    
           char* getExtension                (const char* pPath);

    std::vector<std::string> parsePath         (const char* pPath);
    std::vector<std::string> parsePath_withBase(const char* pPath);
    
    bool isFile(const char*        pPath);
    bool isFile(const std::string&  path);
    bool isDir (const char*        pPath);
    bool isDir (const std::string&  path);
    
    bool fileExist(const char*        pPath);
    bool fileExist(const std::string&  path);
    bool  dirExist(const char*        pPath);
    bool  dirExist(const std::string&  path);
    bool pathExist(const char*        pPath);
    bool pathExist(const std::string&  path);
}
```


## Description
| Function name | Description |
| ------------- | ----------- |
| getPath()      | A function to get the path from string include path and file name. When a path like `/abc/def/example.txt`, `/abc/def` is returned.<br> |
| getPath_owWC() | <br> |
| getDirName()              | <br> |
| getDirName_begin_idx()    | <br> |
| getDirName_end_idx()      | <br> |
| getDirName_end_idx_owWC() | <br> |
| getFileName()                  | <br> |
| getFileName_withoutExtension() | <br> |
| getExtension()                 | <br> |
| parsePath()          | <br> |
| parsePath_withBase() | <br> |
| isFile()      | <br> |
| isDir()       | <br> |
| fileExist()   | <br> |
| dirExist()    | <br> |
| pathExist()   | <br> |


## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string path = "./abc/DEF/example.txt";
    sstd::printn( sstd::getPath(path.c_str()) );
    sstd::printn( sstd::getFileName(path.c_str()) );
    sstd::printn( sstd::getFileName_withoutExtension(path.c_str()) );
    sstd::printn( sstd::getExtension(path.c_str()) );
    printf("\n");
    
    sstd::printn( sstd::parsePath(path.c_str()) );
    sstd::printn( sstd::parsePath_withBase(path.c_str()) );
    printf("\n");
    
    std::string path_dir  = "./tmp";
    std::string path_file = "./tmp/example.txt";
    sstd::system(sstd::ssprintf("mkdir %s", path_dir.c_str()));
    sstd::system(sstd::ssprintf("touch %s", path_file.c_str()));
    
    sstd::printn( sstd::isFile(path_dir.c_str()) );
    sstd::printn( sstd::isFile(path_file.c_str()) );
    printf("\n");
    
    sstd::printn( sstd::isDir(path_dir.c_str()) );
    sstd::printn( sstd::isDir(path_file.c_str()) );
    printf("\n");

    sstd::printn( sstd::fileExist(path_file.c_str()) );
    sstd::printn( sstd::dirExist(path_dir.c_str()) );
    printf("\n");
    
    sstd::rm(path_dir);
    sstd::printn( sstd::fileExist(path_file.c_str()) );
    sstd::printn( sstd::dirExist(path_dir.c_str()) );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/path.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/path.cpp)
- Header: [sstd/src/path.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/path.hpp)
- Test: [test/path.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/path.hpp)
  (Not implemented yet)

