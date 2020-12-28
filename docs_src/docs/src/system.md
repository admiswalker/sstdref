# system
## Abstract
```system()``` executes the specified command.  
```system()``` は指定されたコマンドを実行します．

## Header file
```cpp
namespace sstd{
    int system(const        char* str);
    int system(const std::string& str);
}
```

## Usage
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::system("mkdir -p ./tmp/a/b/c");
    sstd::system("tree ./tmp");
    sstd::system("rm -rf ./tmp");
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/stdlib.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/stdlib.cpp)
- Header: [sstd/src/stdlib.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/stdlib.hpp)
- Test: [test/stdlib.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/stdlib.hpp)
  (Not implemented yet)

