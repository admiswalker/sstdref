# sleep
## Abstract
```sleep``` waits for the specified time.  
```sleep``` は指定時間待機します．

## Header file
```cpp
namespace sstd{
    inline void sleep_hour(uint rhs);
    inline void sleep_min (uint rhs);
    inline void sleep_s   (uint rhs);
    inline void sleep_ms  (uint rhs);
    inline void sleep_us  (uint rhs);
    inline void sleep_ns  (uint rhs);
}
```

## Usage
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    time_m timem; sstd::measureTime_start(timem);

    sstd::sleep_s(1);
    sstd::sleep_ms(100);
    sstd::sleep_us(11*1000);

    sstd::measureTime_stop_print(timem);
    return 0;
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Header: [sstd/src/sleep.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/sleep.hpp)
- Test: [test/sleep.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/sleep.hpp)
  (Not implemented yet)

