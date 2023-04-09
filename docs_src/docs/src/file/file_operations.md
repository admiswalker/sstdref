# file_operations
## Abstract
This file contains the file operations.  
このファイルでは，ファイルへの操作を収録します．


## Header file
```cpp
namespace sstd{
    bool file_size(size_t& ret_size, const char* path);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| file_size()   | gets the size of the file in the path.<br>path に指定されたファイルのサイズを取得します． |


## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    const char* path = "./tmp/dummy_file";
    sstd::system(sstd::ssprintf("head -c 19842 /dev/urandom > %s", path)); // generate 19842 Byte random file

    size_t ret_size=0ull;
    bool ret = sstd::file_size(ret_size, path);
    sstd::printn(ret);
    sstd::printn(ret_size);

    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/file_operations.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/file_operations.cpp)
- Header: [sstd/src/file/file_operations.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/file_operations.hpp)
- Test: [test/src_test/file/file_operations.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/file_operations.cpp)

