# manipulation
## Abstract
This file contains the manipulation functions for generalized `std::vector<T>` template.<br/>
このファイルでは，一般化された `std::vector<T>` テンプレートを操作する関数を収録します．

## Header file
```cpp
namespace sstd{
    template<typename T> std::vector<T> rmEmpty   (const std::vector<T>& vec); // remove empty elements
    template<typename T> void           rmEmpty_ow(      std::vector<T>& vec); // remove empty elements overwrite
    
    template<typename T> std::vector<T> rmEmpty_l   (const std::vector<T>& vec); // remove empty elements from left side
    template<typename T> void           rmEmpty_l_ow(      std::vector<T>& vec); // remove empty elements from left side overwrite
    
    template<typename T> std::vector<T> rmEmpty_r   (const std::vector<T>& vec); // remove empty elements from right side
    template<typename T> void           rmEmpty_r_ow(      std::vector<T>& vec); // remove empty elements from right side overwrite
    
    // rmEmpty_ow(arg1, arg2, ...) of multiple vector arguments
    template<typename Head, typename... Tail> inline void rmEmpty_ow(Head&& head, Tail&&... tail);
    
    //---

    template<typename T> uint cntEmpty  (const std::vector<T>& vec); // count empty elements
    template<typename T> uint cntEmpty_l(const std::vector<T>& vec); // count empty elements from left side
    template<typename T> uint cntEmpty_r(const std::vector<T>& vec); // count empty elements from right side
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| rmEmpty   ()   | returns the `std::vector<T>` type which is removed empty objects and .<br>空のオブジェクトを取り除いた `std::vector<T>` 型を返却します． |
| rmEmpty_ow()   | removes empty objects and overwrites the results to the input argument.<br>空のオブジェクトを取り除き，入力を上書きします． |
| rmEmpty_l   () | returns as the `std::vector<T>` type which is removed empty objects from left (head) side.<br>空のオブジェクトを左 (先頭) 側から取り除いた `std::vector<T>` 型を返却します． |
| rmEmpty_l_ow() | removes empty objects from left (head) side and overwrites the results to the input argument.<br>空のオブジェクトを左 (先頭) 側から取り除き，入力を上書きします． |
| rmEmpty_r   () | returns as the `std::vector<T>` type which is removed empty objects from right (head) side.<br>空のオブジェクトを右 (末尾) 側から取り除いた `std::vector<T>` 型を返却します． |
| rmEmpty_r_ow() | removes empty objects from right (head) side and overwrites the results to the input argument.<br>空のオブジェクトを右 (末尾) 側から取り除き，入力を上書きします． |
| rmEmpty_ow(arg1, arg2, ...)   | removes empty objects and overwrites the results to the input arguments based on the first argment.<br>第一引数のオブジェクトに従って，空のオブジェクトを取り除き，入力を上書きします． |
| cntEmpty   | returns the number of empty objects.<br>空のオブジェクトの数を返却します． |
| cntEmpty_l | returns the number of empty objects counted from left (head) side.<br>左 (先頭) 側から数えた空のオブジェクトの数を返却します． |
| cntEmpty_r | returns the number of empty objects counted from right (tail) side.<br>右 (末尾) 側から数えた空のオブジェクトの数を返却します． |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    printf("--- rmEmpty ---\n");
    printf("case1:\n");
    
    // case1_1
    std::vector<std::string> v1_1 = {"", "", "2", "3", "", "5", "", ""};
    sstd::printn( sstd::rmEmpty(v1_1) );
    
    // case1_2
    std::vector<std::string> v1_2 = {"", "", "2", "3", "", "5", "", ""};
    sstd::rmEmpty_ow(v1_2);
    sstd::printn( v1_2 );
    
    printf("\n");
    //---
    printf("case2:\n");
    
    // case2_1
    std::vector<std::string> v2_1 = {"", "", "2", "3", "", "5", "", ""};
    sstd::printn( sstd::rmEmpty_l(v2_1) );
    
    // case2_2
    std::vector<std::string> v2_2 = {"", "", "2", "3", "", "5", "", ""};
    sstd::rmEmpty_l_ow(v2_2);
    sstd::printn( v2_2 );
    
    printf("\n");
    //---
    printf("case3:\n");
    
    // case3_1
    std::vector<std::string> v3_1 = {"", "", "2", "3", "", "5", "", ""};
    sstd::printn( sstd::rmEmpty_r(v3_1) );
    
    // case3_2
    std::vector<std::string> v3_2 = {"", "", "2", "3", "", "5", "", ""};
    sstd::rmEmpty_r_ow(v3_2);
    sstd::printn( v3_2 );

    printf("\n");
    //---
    printf("case4: multiple arguments\n");
    
    std::vector<std::string> v4_1 = {  "",   "", "2a", "3a",   "", "5a",   "",   ""};
    std::vector<std::string> v4_2 = {"0b", "1b", "2b", "3b", "4b", "5b", "6b", "7b"};
    std::vector<std::string> v4_3 = {"0c", "1c", "2c", "3c", "4c", "5c", "6c", "7c"};
    sstd::rmEmpty_ow(v4_1, v4_2, v4_3);
    sstd::printn( v4_1 );
    sstd::printn( v4_2 );
    sstd::printn( v4_3 );
    
    printf("\n");
    //---
    printf("--- cntEmpty ---\n");

    std::vector<std::string> v = {"", "", "2", "3", "", "5", "", ""};
    
    sstd::printn( sstd::cntEmpty  (v) );
    sstd::printn( sstd::cntEmpty_l(v) );
    sstd::printn( sstd::cntEmpty_r(v) );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix

## Implementation
- Header: [sstd/src/container/vector/vec_manipulation.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/container/vector/vec_manipulation.hpp)
- Test: [test/container/vector/vec_manipulation.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/container/vector/vec_manipulation.cpp)
