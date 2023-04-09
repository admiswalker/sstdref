# Tr (Transpose)
## Abstract
`Tr()` are the transpose functions for `std::vector<std::vector<T>>`.  
`Tr()` は `std::vector<std::vector<T>>` を転置するための関数です.

## Header file
```cpp
namespace sstd{
    template <typename T> std::vector<std::vector<T>> Tr(const std::vector<std::vector<T>>&  rhs);
    template <typename T> std::vector<std::vector<T>> Tr(      std::vector<std::vector<T>>&& rhs);
}
```

## Usage
### Transpose. Ex: 1
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::vector<int>> vvec = {
        { 1, 2, 3 }
    };
    sstd::printn(vvec);
    
    std::vector<std::vector<int>> vvecTr = sstd::Tr(vvec);
    sstd::printn(vvecTr);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Transpose. Ex: 2
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::vector<int>> vvec = {
        { 1,  2,  3}, 
        { 4,  5,  6}, 
        { 7,  8,  9}
    };
    sstd::printn(vvec);
    
    std::vector<std::vector<int>> vvecTr = sstd::Tr(vvec);
    sstd::printn(vvecTr);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Transpose. Ex: 3
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::vector<int>> vvec = {
        { 1}, 
        { 2,  3}, 
        { 4,  5,  6}
    };
    sstd::printn(vvec);
    
    std::vector<std::vector<int>> vvecTr = sstd::Tr(vvec);
    sstd::printn(vvecTr);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```




## Implementation
- Source: header only
- Header: [sstd/src/container/vector/vvec.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/container/vector/vvec.hpp)
- Test: [test/src_test/container/vector/vvec.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/container/vector/vvec.cpp)
