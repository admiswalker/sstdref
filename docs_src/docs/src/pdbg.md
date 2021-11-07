# pdbg
## Abstract
`pdbg` prints debug information.  
`pdbg` はデバッグ情報を出力します．

## Header file
```cpp
namespace sstd{
    inline void pdbg(...){}
    inline void pdbg_if(...){}
    inline void pdbg_if_exit(...){}
    inline void pdbg_if_stop_exit(...){}
    inline void dbg(...){}
    inline void ndbg(...){}
}
```

## Usage
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::pdbg("ERROR: printing error reasons.\n");
    printf("\n");
    
    printf("True: "); sstd::pdbg_if(true, "ERROR: printing error reasons.\n");
    printf("False: "); sstd::pdbg_if(false, "ERROR: printing error reasons.\n"); printf("\n");
    
    return 0;
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/XXXXXX.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/XXXXXX.cpp)
- Header: [sstd/src/XXXXXX.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/XXXXXX.hpp)
- Test: [test/XXXXXX.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/XXXXXX.hpp)
  (Not implemented yet)

