# path
## Abstract
`path.hpp` contains functions for path editing.  
`path.hpp` はパス編集用の関数を収録します．

## Header file
```cpp
namespace sstd{
    std::string  getPath                     (const char* pPath);
    std::string  getPath_woWC                (const char* pPath); // _woWC: without wildcard
    
    std::string  getDirName                  (const char* pPath);
    uint         getDirName_begin_idx        (const char* pPath);
    uint         getDirName_end_idx          (const char* pPath);
    uint         getDirName_end_idx_woWC     (const char* pPath); // _woWC: without wildcard
    
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
| getPath()      | A function to get a path when a string of 1st arg is consisted of a path and a file name. For example, when a 1st argument has `/abc/def/example.txt`, `/abc/def` is returned.<br> |
| getPath_woWC() | A function to get a path without wildcard (`*` or `?`). For example, when a 1st argument has `/abc/d??/*.txt`, `/abc` is returned. And when a 1st argument has `/abc/def/example.txt`, `/abc/def` is returned. (_woWC means without wildcard).<br> |
| getDirName()              | A function to get a nearest directory name from file name when a string of 1st arg which is consisted of a path and a file name. For example, when a 1st argument has `/abc/def/example.txt`, `def` is returned. <br> |
| getDirName_begin_idx()    | A function to get a beginning index number of the nearest directory name from file name when a string of 1st arg is consisted of a path and a file name.<br> |
| getDirName_end_idx()      | A function to get a ending index number of the nearest directory name from file name when a string of 1st arg is consisted of a path and a file name.<br> |
| getDirName_end_idx_owWC() | A function to get a ending index number of the nearest directory name from file name without wildcard when a string of 1st arg which is consisted of a path and a file name.<br> |
| getFileName()                  | A function to get a file name when a string of 1st arg is consisted of a path and a file name. For example, when a 1st argument has `/abc/def/example.txt`, `example.txt` is returned.<br> |
| getFileName_withoutExtension() | A function to get a file name without file extension when a string of 1st arg is consisted of a path and a file name. For example, when a 1st argument has `/abc/def/example.txt`, `example` is returned. And when a 1st argument has `/abc/def/example.txt.zip`, `example.txt` is returned.<br> |
| getExtension()                 | <br> |
| parsePath()          | <br> |
| parsePath_withBase() | <br> |
| isFile()      | <br> |
| isDir()       | <br> |
| fileExist()   | <br> |
| dirExist()    | <br> |
| pathExist()   | <br> |


## Usage
### getPath(), getPath_woWC()
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

### getDirName(), getDirName_begin_idx(), getDirName_end_idx(), getDirName_end_idx_owWC()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string path = "./abc/def/example.txt";
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

### getFileName(), getFileName_withoutExtension()


### getExtension()


### parsePath(), parsePath_withBase()


### isFile(), isDir(), fileExist(), dirExist(), pathExist()



## Implementation
- Source: [sstd/src/path.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/path.cpp)
- Header: [sstd/src/path.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/path.hpp)
- Test: [test/path.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/path.hpp)
  (Not implemented yet)

