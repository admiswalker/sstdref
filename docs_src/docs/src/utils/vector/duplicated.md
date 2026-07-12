# duplicated
## Abstract
`duplicated.hpp` contains the functions to resolve duplicated items in the `std::vector<T>`.  
`duplicated.hpp` は，`std::vector<T>` に含まれる要素の重複を解決する処理を収録している．

## Header file
```cpp
namespace sstd{
    template<typename T>
    std::vector<std::tuple<T,uint>> duplicated_key_cnt(const std::vector<T>& v);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| function01()  | en-xxxxxxx<br>ja-xxxxxxx |
| function02()  | en-xxxxxxx<br>ja-xxxxxxx |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = "Hello template!";
    sstd::printn(s);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix

## Implementation
- Header: [sstd/src/utils/vector/duplicated.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/utils/vector/duplicated.hpp)
- Test: [test/src_test/utils/vector/duplicated.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/utils/vector/duplicated.cpp)