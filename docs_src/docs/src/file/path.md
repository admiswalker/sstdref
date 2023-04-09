# path
## Abstract
`path.hpp` contains functions for path editing.  
`path.hpp` はパス編集用の関数を収録します．

## Header file
```cpp
namespace sstd{
    std::string  path2basePath            (const char* pPath);
    std::string  path2basePath_woWC       (const char* pPath); // _woWC: without wild card
    
    std::string  path2dirName             (const char* pPath);
    uint         path2dirName_begin_idx   (const char* pPath);
    uint         path2dirName_end_idx     (const char* pPath);
    uint         path2dirName_end_idx_woWC(const char* pPath); // _woWC: without wild card
    
           char* path2fileName            (const        char* pPath);
    std::string  path2fileName            (const std::string&  path);
    std::string  path2fileName_woExt      (const        char* pPath);
           char* path2fileExt             (const        char* pPath);
    std::string  path2fileExt             (const std::string&  path);
    
    std::vector<std::string> parsePath          (const char* pPath);
    std::vector<std::string> parsePath_wBasePath(const char* pPath); // _wBasePath: with base path
    
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

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Below functions are the not recommended to use. (Below functions will be delete on sstd ver 3.x.x).

namespace sstd{
    
    std::string  getPath                     (const char* pPath); // new name: path2basePath()
    std::string  getPath_woWC                (const char* pPath); // new name: path2basePath_woWC()
    
    std::string  getDirName                  (const char* pPath); // new name: path2dirName()
    uint         getDirName_begin_idx        (const char* pPath); // new name: path2dirName_begin_idx()
    uint         getDirName_end_idx          (const char* pPath); // new name: path2dirName_end_idx()
    uint         getDirName_end_idx_woWC     (const char* pPath); // new name: path2dirName_end_idx_woWC()
    
           char* getFileName                 (const char* pPath); // new name: path2fileName()
    std::string  getFileName_withoutExtension(const char* pPath); // new name: path2fileName_woExt()
    
           char* getExtension                (const char* pPath); // new name: path2fileExt()
    
    std::vector<std::string> parsePath_withBase(const char* pPath); // new name: parsePath_wBasePath()
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
```


## Description
| Function name | Description |
| ------------- | ----------- |
| path2basePath()<br/><s>getPath()</s> will be delete           | A function to get a path when a string of 1st arg is consisted of a path and a file name.<br> |
| path2basePath_woWC()<br/><s>getPath_woWC()</s> will be delete | A function to get a path without wildcard (`*` or `?`). (_woWC means without wildcard).<br> |
| path2dirName()<br/><s>getDirName()</s> will be delete         | A function to get a nearest directory name from file name when a string of 1st arg which is consisted of a path and a file name.<br> |
| path2dirName_begin_idx()<br/><s>getDirName_begin_idx()</s> will be delete       | A function to get a beginning index number of the nearest directory name from file name when a string of 1st arg is consisted of a path and a file name.<br> |
| path2dirName_end_idx()<br/><s>getDirName_end_idx()</s> will be delete           | A function to get a ending index number of the nearest directory name from file name when a string of 1st arg is consisted of a path and a file name. In detail, the ending index number is defined next to the ending character.<br> |
| path2dirName_end_idx_woWC()<br/><s>getDirName_end_idx_owWC()</s> will be delete | A function to get a ending index number of the nearest directory name from file name without wildcard when a string of 1st arg which is consisted of a path and a file name. In detail, the ending index number is defined next to the ending character.<br> |
| path2fileName()<br/><s>getFileName()</s> will be delete               | A function to get a file name when a string of 1st arg is consisted of a path and a file name.<br> |
| path2fileName_woExt()<br/><s>getFileName_withoutExtension()</s> will be delete  | A function to get a file name without file extension when a string of 1st arg is consisted of a path and a file name.<br> |
| path2fileExt()<br/><s>getExtension()</s> will be delete               | A function to get a file extension. When a string of 1st arg does not have a file extension, 0 length string is returned.<br> |
| parsePath()                                                           | A function to parse a path by `/` or `\\`.<br> |
| parsePath_wBasePath()<br/><s>parsePath_withBase()</s> will be delete  | A function to parse a path by `/` or `\\` and return with the base path from the 1st arg.<br> |
| isFile()      | Exactory same as the `fileExist()`<br> |
| isDir()       | Exactory same as the `dirExist()`<br> |
| fileExist()   | A function to judge whether a file is exist or not.<br> |
| dirExist()    | A function to judge whether a directory is exist or not.<br> |
| pathExist()   | A function to judge whether a path is exist or not.<br> |


## Usage
### path2basePath(), path2basePath_woWC()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::path2basePath("./abc/def/example.txt") );
    sstd::printn( sstd::path2basePath("./abc/def/") );
    sstd::printn( sstd::path2basePath("./abc/def") );
    printf("\n");
    
    sstd::printn( sstd::path2basePath_woWC("./abc/def/example.txt") );
    sstd::printn( sstd::path2basePath_woWC(R"(./abc/d??/*.txt)") );
}
```
NOTE: This sample use `raw string literals R"()"` to avoid `unknown escape sequence: '\*'` error.

- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### path2dirName(), path2dirName_begin_idx(), path2dirName_end_idx(), path2dirName_end_idx_owWC()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::path2dirName("./abc/def") );
    sstd::printn( sstd::path2dirName("./abc/def/") );
    printf("\n");
    
    sstd::printn( sstd::path2dirName("./abc/def/example.txt") ); // NOTE: path2dirName() treats end name as a direcotry name. If you want to parse this type of path, write like bolow line.
    sstd::printn( sstd::path2dirName(sstd::path2basePath("./abc/def/example.txt")) );
    printf("\n");
    
    sstd::printn( sstd::path2dirName_begin_idx("./abc/def/") );
    printf("\n");
    
    sstd::printn( sstd::path2dirName_end_idx("./abc/def/") );
    sstd::printn( sstd::path2dirName_end_idx_woWC("./abc/def/") );
    sstd::printn( sstd::path2dirName_end_idx_woWC(R"(./abc/d??/)") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### path2fileName(), path2fileName_woExt()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::path2fileName("./abc/def/example.txt") );
    sstd::printn( sstd::path2fileName("./abc/def/example") );
    printf("\n");
    
    sstd::printn( sstd::path2fileName_woExt("./abc/def/example.txt") );
    sstd::printn( sstd::path2fileName_woExt("./abc/def/example") );
    sstd::printn( sstd::path2fileName_woExt("./abc/def/example.txt.zip") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### path2fileExt()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::path2fileExt("./abc/def/example.txt") );
    sstd::printn( sstd::path2fileExt("./abc/def/example") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### parsePath(), parsePath_wBasePath()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::parsePath("./abc/def/example.txt") );
    sstd::printn( sstd::parsePath_wBasePath("./abc/def/example") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### isFile(), isDir(), fileExist(), dirExist(), pathExist()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    // sstd::isFile() is exactory same as the `sstd::fileExist()`.
    // sstd::isDir() is exactory same as the `sstd::dirExist()`.
    
    sstd::printn( sstd::fileExist("./tmp/abc/def/example.txt") );
    sstd::printn( sstd::dirExist("./tmp/abc/def") );
    sstd::printn( sstd::pathExist("./tmp/abc/def") );
    sstd::printn( sstd::pathExist("./tmp/abc/def/example.txt") );
    printf("\n");

    sstd::mkdir("tmp");
    sstd::mkdir("./tmp/abc/def");
    sstd::system("touch ./tmp/abc/def/example.txt");
    
    sstd::printn( sstd::fileExist("./tmp/abc/def/example.txt") );
    sstd::printn( sstd::dirExist("./tmp/abc/def") );
    sstd::printn( sstd::pathExist("./tmp/abc/def") );
    sstd::printn( sstd::pathExist("./tmp/abc/def/example.txt") );
    
    sstd::rm("tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/path.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/path.cpp)
- Header: [sstd/src/file/path.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/path.hpp)
- Test: [test/src_test/file/path.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/path.cpp)

