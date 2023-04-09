# vec / vvec
## Abstract
Type definitions on SSTD. These definitions are read by `#include <sstd/sstd.hpp>`.  
SSTD における型の定義．`#include <sstd/sstd.hpp>` により定義が読み込まれる．

## Header file
```cpp
namespace sstd{
    template <class T> using  vec =             std::vector<T>;
    template <class T> using vvec = std::vector<std::vector<T>>;
}
```

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::vec<int> v = {1, 2, 3}; // same as a "std::vector<int> v = {1, 2, 3};"
    sstd::printn(v);

    sstd::vvec<int> vv = {{1, 2, 3}, {4, 5, 6}}; // same as a "std::vector<vector<int>> vv = {{1, 2, 3}, {4, 5, 6}};"
    sstd::printn(vv);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: header only
- Header: [sstd/src/container/vector/typeDef.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/container/vector/typeDef.hpp)
- Test: [test/src_test/container/vector/typeDef.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/container/vector/typeDef.cpp)
  (Not implemented yet)

