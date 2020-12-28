# mkdir
## Abstract
```mkdir``` creates directories recursively.  
```mkdir``` はディレクトリを再帰的に作成します．

## Header file
```c++
namespace sstd{
    void mkdir(const char*        pPath);
    void mkdir(const std::string&  path);
}
```

## Usage
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp/a/b/c/");
    
    sstd::system("cd ./tmp; ls");
    sstd::system("cd ./tmp/a; ls");
    sstd::system("cd ./tmp/a/b; ls");
    
    sstd::rm("./tmp");
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/mkdir.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/mkdir.cpp)
- Header: [sstd/src/mkdir.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/mkdir.hpp)
- Test: [test/mkdir.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/mkdir.hpp)
  (Not implemented yet)

