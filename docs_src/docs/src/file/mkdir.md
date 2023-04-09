# mkdir
## Abstract
`mkdir` creates directories recursively.  
`mkdir` はディレクトリを再帰的に作成します．

## Header file
```cpp
namespace sstd{
    void mkdir(const char*        pPath);
    void mkdir(const std::string&  path);
}
```

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp/a/b/c/");
    
    sstd::system("tree ./tmp");
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/mkdir.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/mkdir.cpp)
- Header: [sstd/src/mkdir.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/mkdir.hpp)
- Test: [test/src_test/file/mkdir.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/mkdir.cpp)
  (Not implemented yet)

