# print
## Abstract
The print() function for `sstd::terp::var`.

`sstd::terp::var` 向け print() 関数．

## Header file
```cpp
namespace sstd{
    void print(const sstd::terp::var& rhs);
    void for_printn(const sstd::terp::var& rhs);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| print()      | is an implementation for `sstd::print()`.<br>ja-xxxxxxx |
| for_printn() | is an implementation for `sstd::printn()` macro defined at [print/printn](../../print/print.md).<br>`sstd::printn()` マクロ向け実装．マクロ実装は [print/printn](../../print/print.md) を参照すること． |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(3);
    x[0] = "a";
    x[1] = sstd::terp::list(2);
    x[1][0] = "b";
    x[1][1] = "c";
    x[2] = sstd::terp::hash();
    x[2]["key"] = "value";

    sstd::print(x);
    sstd::printn(x); // a `printn` macro is replaced to the variable name of 'x', string ' = ' and `for_pirntn()`.
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/memory/terp/print.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/terp/print.cpp)
- Header: [sstd/src/memory/terp/print.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/terp/print.hpp)
- Test: [test/memory/terp/terp_print.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/memory/terp/terp_print.cpp)

