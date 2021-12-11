# ssprintf
## Abstract
`ssprintf()` is the `std::string` version of  `sprintf()`.  
`ssprintf()` は，`sprintf()` の `std::string` 版です．

## Header file
```cpp
namespace sstd{
    std::string ssprintf(const char* format, ...);
}
```

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = sstd::ssprintf("%s %d%d%d %03d", "ABC", 0, 1, 2, 3);
    sstd::printn(s);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/ssprintf.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/ssprintf.cpp)
- Header: [sstd/src/ssprintf.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/ssprintf.hpp)
- Test: [test/ssprintf.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/ssprintf.hpp)
  (Not implemented yet)

