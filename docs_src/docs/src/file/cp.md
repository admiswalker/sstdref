# cp
## Abstract
Functions to copy files and directories

## Header file
```cpp
namespace sstd{
    bool copy(const char*        pPath_src, const char*        pPath_dst, const char* opt);
    bool copy(const std::string&  path_src, const char*        pPath_dst, const char* opt);
    bool copy(const char*        pPath_src, const std::string&  path_dst, const char* opt);
    bool copy(const std::string&  path_src, const std::string&  path_dst, const char* opt);
    bool copy(const char*        pPath_src, const char*        pPath_dst);
    bool copy(const std::string&  path_src, const char*        pPath_dst);
    bool copy(const char*        pPath_src, const std::string&  path_dst);
    bool copy(const std::string&  path_src, const std::string&  path_dst);
    
    bool cp  (const char*        pPath_src, const char*        pPath_dst, const char* opt);
    bool cp  (const std::string&  path_src, const char*        pPath_dst, const char* opt);
    bool cp  (const char*        pPath_src, const std::string&  path_dst, const char* opt);
    bool cp  (const std::string&  path_src, const std::string&  path_dst, const char* opt);
    bool cp  (const char*        pPath_src, const char*        pPath_dst);
    bool cp  (const std::string&  path_src, const char*        pPath_dst);
    bool cp  (const char*        pPath_src, const std::string&  path_dst);
    bool cp  (const std::string&  path_src, const std::string&  path_dst);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| copy()        | A function to copy a single file, and give the same permission as the source.<br>1 つのファイルをコピーする関数．コピー元のファイルと同一のパーミッションを付与します． |
| cp()          | A function to copy files and directories, and give the same permission as the source.<br>複数のファイルやディレクトリをコピーする関数．コピー元のファイルやディレクトリと同一のパーミッションを付与します． |

**options**<br>
- `n`: (n: no overwrite) do not to overwrite the existing file.<br>
- `p`: (p: permission) copy file with the same permission and timestamp.<br>
- `u`: (u: update) update the file only when the dst file is older than src file.<br>


## Usage
### copy(): copy a file
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("dd if=/dev/urandom of=./tmp/rand.bin bs=1M count=10 > /dev/null 2>&1");
    
    sstd::copy("./tmp/rand.bin", "./tmp/rand_copy.bin");
    sstd::system("ls ./tmp");
    sstd::system("sha256sum ./tmp/rand.bin | cut -d \" \" -f 1");
    sstd::system("sha256sum ./tmp/rand_copy.bin | cut -d \" \" -f 1");

    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### cp(): copy a directory
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    
    sstd::cp("./sstd", "./tmp");
    sstd::system("ls ./tmp");
    
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### cp(): copy under the directory
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    
    sstd::cp("./sstd/*", "./tmp");
    sstd::system("ls ./tmp");
    
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/cp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/cp.cpp)
- Header: [sstd/src/file/cp.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/cp.hpp)
- Test: [test/src_test/file/cp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/cp.cpp)

