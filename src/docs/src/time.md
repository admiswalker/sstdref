# time
## Abstract
C/C++ における時刻計算は，tm 構造体や unixtime により処理する．
しかしながら，gcc と MSVC++ ではそれぞれに関数名が異なる． また，関数の名も直感的ではない． したがって，sstd では，これらの関数をラップした．

## Header file
```c++
namespace sstd{
    struct tm time2tm       (time_t unixtime);
    time_t    tm2time       (struct tm& rhs);
    struct tm timeGm2tmLocal(time_t unixtime);
    time_t    tmLocal2timeGm(struct tm& rhs);
    std::string time2str    (time_t unixtime);
    std::string   tm2str    (struct tm& rhs);
    double      time2unixday(time_t unixtime);
    double        tm2unixday(struct tm& rhs);
    
    time_t    yday2time(uint year, uint yday);
    struct tm yday2tm  (uint year, uint yday);
    
    struct timeval getTimeval();
    
    double unixtime2JulianDate(time_t unixtime);
    double Julius_T(time_t unixtime);
    double JulianDate2Julius_T(double JulianDate);
    double TJuliusD(time_t unixtime);
    double JulianDate2TJuliusD(double JulianDate);
    
    void print(const struct tm& rhs);
    void for_printn(const struct tm& rhs);
}
```

## Usage

## Others
- Implementation: [sstd/src/time.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/time.hpp)
- Test code: [test/time.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/time.hpp) (Not implemented yet)

