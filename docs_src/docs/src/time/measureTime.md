# measureTime
## Abstract
`measureTime` measures the execution time.  
`measureTime` は実行時間を計測します．

## Header file
```cpp
namespace sstd{
    void        measureTime_start     (      time_m& startTime);
    double      measureTime_stop_s    (const time_m& startTime); // sec
    double      measureTime_stop_ms   (const time_m& startTime); // milli sec
    double      measureTime_stop_us   (const time_m& startTime); // micro sec
    double      measureTime_stop_ns   (const time_m& startTime); // nano sec
    std::string measureTime_ms2str    (uint64 tmp);
    std::string measureTime_stop_str  (const time_m& startTime);
    void        measureTime_stop_print(const time_m& startTime);
}
```

## Usage
### Measurement of execution time. (実行時間の計測)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf("|                                                   |\n");
    printf("|     Welcome to Sub Standard Library (SSTD) !      |\n");
    printf("|                                                   |\n");
    printf("+---------------------------------------------------+\n");
    printf("\n");
    printf("■ measureTime_start---------------\n\n"); time_m timem; sstd::measureTime_start(timem);
    
    sstd::sleep_s(1);
    sstd::sleep_ms(100);
    sstd::sleep_us(11*1000);
    
    printf("\n");
    printf("■ measureTime_stop----------------\n");
    sstd::measureTime_stop_print(timem);
    sstd::pauseIfWin32();
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Lap time measurement. (ラップタイムの測定)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> vLT_ms;
    
    time_m timem;
    sstd::measureTime_start(timem);
    vLT_ms.push_back( sstd::measureTime_stop_ms(timem) );
    
    for(uint i=0; i<5; ++i){
        sstd::sleep_ms(10);
        vLT_ms.push_back( sstd::measureTime_stop_ms(timem) );
    }
    
    sstd::printn(vLT_ms);
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/measureTime.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/measureTime.cpp)
- Header: [sstd/src/measureTime.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/measureTime.hpp)
- Test: [test/measureTime.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/measureTime.hpp)
