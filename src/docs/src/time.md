# time
## Abstract
```struct tm``` と ```time_t``` (unixtime) および，その他の時刻を相互変換する．

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
- input
```cpp
#include <sstd/sstd.hpp>
#include <time.h>

int main(){
    time_t unixtime_UTC; time(&unixtime_UTC); // get current unixtime (UTC)
    struct tm tm_UTC = sstd::time2tm(unixtime_UTC);
    struct tm tm_Local = sstd::timeGm2tmLocal(unixtime_UTC);
    
    sstd::printn(unixtime_UTC);
    sstd::printn(tm_UTC);
    sstd::printn(tm_Local);
}
```
- output  
Below is the result on Japanese local time (UTC+9hour).
```
unixtime_UTC = 1608991553
tm_UTC = 2020-12-26 14:05:53
tm_Local = 2020-12-26 23:05:53
```

## Appendix
```c++
struct tm{
  int tm_sec;      /* 秒 [0-61] 最大2秒までのうるう秒を考慮 */
  int tm_min;      /* 分 [0-59] */
  int tm_hour;     /* 時 [0-23] */
  int tm_mday;     /* 日 [1-31] */
  int tm_mon;      /* 月 [0-11] 0から始まることに注意 */
  int tm_year;     /* 年 [1900からの経過年数] */
  int tm_wday;     /* 曜日 [0:日 1:月 ... 6:土] */
  int tm_yday;     /* 年内の通し日数 [0-365] 0から始まることに注意*/
  int tm_isdst;    /* 夏時間が無効であれば 0 */
};
```

- ref: [localtime - 初心者のためのポイント学習 C 言語](http://www9.plala.or.jp/sgwr-t/lib/localtime.html)

## Others
- Implementation: [sstd/src/time.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/time.hpp)
- Test code: [test/time.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/time.hpp) (Not implemented yet)

