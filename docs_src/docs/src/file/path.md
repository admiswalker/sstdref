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
| getPath()      | A function to get a path when a string of 1st arg is consisted of a path and a file name.<br> |
| getPath_woWC() | A function to get a path without wildcard (`*` or `?`). (_woWC means without wildcard).<br> |
| getDirName()              | A function to get a nearest directory name from file name when a string of 1st arg which is consisted of a path and a file name.<br> |
| getDirName_begin_idx()    | A function to get a beginning index number of the nearest directory name from file name when a string of 1st arg is consisted of a path and a file name.<br> |
| getDirName_end_idx()      | A function to get a ending index number of the nearest directory name from file name when a string of 1st arg is consisted of a path and a file name. In detail, the ending index number is defined next to the ending character.<br> |
| getDirName_end_idx_owWC() | A function to get a ending index number of the nearest directory name from file name without wildcard when a string of 1st arg which is consisted of a path and a file name. In detail, the ending index number is defined next to the ending character.<br> |
| getFileName()                  | A function to get a file name when a string of 1st arg is consisted of a path and a file name.<br> |
| getFileName_withoutExtension() | A function to get a file name without file extension when a string of 1st arg is consisted of a path and a file name.<br> |
| getExtension()                 | A function to get a file extension. When a string of 1st arg does not have a file extension, 0 length string is returned.<br> |
| parsePath()          | A function to parse a path by `/` or `\\`.<br> |
| parsePath_withBase() | A function to parse a path by `/` or `\\` and return with the base path from the 1st arg.<br> |
| isFile()      | Exactory same as the `fileExist()`<br> |
| isDir()       | Exactory same as the `dirExist()`<br> |
| fileExist()   | A function to judge whether a file is exist or not.<br> |
| dirExist()    | A function to judge whether a directory is exist or not.<br> |
| pathExist()   | A function to judge whether a path is exist or not.<br> |


## Usage
### getPath(), getPath_woWC()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::getPath("./abc/def/example.txt") );
    printf("\n");
    
    sstd::printn( sstd::getPath_woWC("./abc/def/example.txt") );
    sstd::printn( sstd::getPath_woWC(R"(./abc/d??/*.txt)") );
}
```
NOTE: This sample use `raw string literals R"()"` to avoid `unknown escape sequence: '\*'` error.

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
    sstd::printn( sstd::getDirName("./abc/def/example.txt") );
    printf("\n");
    
    sstd::printn( sstd::getDirName_begin_idx("./abc/def/example.txt") );
    printf("\n");
    
    sstd::printn( sstd::getDirName_end_idx("./abc/def/example.txt") );
    sstd::printn( sstd::getDirName_end_idx_woWC("./abc/def/example.txt") );
    sstd::printn( sstd::getDirName_end_idx_woWC(R"(./abc/d??/*.txt)") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### getFileName(), getFileName_withoutExtension()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::getFileName("./abc/def/example.txt") );
    sstd::printn( sstd::getFileName("./abc/def/example") );
    printf("\n");
    
    sstd::printn( sstd::getFileName_withoutExtension("./abc/def/example.txt") );
    sstd::printn( sstd::getFileName_withoutExtension("./abc/def/example") );
    sstd::printn( sstd::getFileName_withoutExtension("./abc/def/example.txt.zip") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### getExtension()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::getExtension("./abc/def/example.txt") );
    sstd::printn( sstd::getExtension("./abc/def/example") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### parsePath(), parsePath_withBase()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::parsePath("./abc/def/example.txt") );
    sstd::printn( sstd::parsePath_withBase("./abc/def/example") );
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
- Test: [test/file/path.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/path.hpp)

