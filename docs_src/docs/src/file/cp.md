# cp
## Abstract
Functions to copy files and direcotries

## Header file
```cpp
namespace sstd{
    bool copy(const char*        pPath_src, const char*        pPath_dst);
    bool copy(const std::string&  path_src, const char*        pPath_dst);
    bool copy(const char*        pPath_src, const std::string&  path_dst);
    bool copy(const std::string&  path_src, const std::string&  path_dst);

    bool cp  (const char*        pPath_src, const char*        pPath_dst);
    bool cp  (const std::string&  path_src, const char*        pPath_dst);
    bool cp  (const char*        pPath_src, const std::string&  path_dst);
    bool cp  (const std::string&  path_src, const std::string&  path_dst);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| copy()        | A function to copy a single file. <br>1 つのファイルをコピーする関数． |
| cp()          | A function to copy files and directories. <br>複数のファイルやディレクトリをコピーする関数． |

## Usage
### copy
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmpDir_cp");
    sstd::system("dd if=/dev/urandom of=./tmpDir_cp/test_rand.bin bs=1M count=10 > /dev/null 2>&1");
    
    sstd::copy("./tmpDir_cp/test_rand.bin", "./tmpDir_cp/test_rand_copy.bin");
    sstd::system("ls ./tmpDir_cp");
    sstd::system("sha256sum ./tmpDir_cp/test_rand.bin | cut -d \" \" -f 1");
    sstd::system("sha256sum ./tmpDir_cp/test_rand_copy.bin | cut -d \" \" -f 1");

    sstd::rm("./tmpDir_cp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### cp (case01)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmpDir_cp");
    
    sstd::cp("./sstd", "./tmpDir_cp");
    sstd::system("ls ./tmpDir_cp");
    
    sstd::rm("./tmpDir_cp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### cp (case02)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmpDir_cp");
    
    sstd::cp("./sstd/*", "./tmpDir_cp");
    sstd::system("ls ./tmpDir_cp");
    
    sstd::rm("./tmpDir_cp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/cp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/cp.cpp)
- Header: [sstd/src/file/cp.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/cp.hpp)
- Test: [test/file/cp.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/cp.hpp)

