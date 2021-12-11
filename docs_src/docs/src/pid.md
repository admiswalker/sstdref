# pid
## Abstract
`getpid` returns the PID of its own process.  
`getpid` は自プロセスの PID を返します．

## Header file
```cpp
namespace sstd{
    int32 getpid();
}
```

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::getpid() );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/pid.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/pid.hpp)
- Header: [sstd/src/pid.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/pid.hpp)
- Test: [test/pid.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/pid.hpp)
  (Not implemented yet)

