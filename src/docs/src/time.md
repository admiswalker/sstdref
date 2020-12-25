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

## Functions
- 空白 (半角スペース) とタブ文字の除去．

| 名前 | 説明 |
| --------- | --- |
| lstrip    | 文字列の先頭にある半角スペースとタブ文字を除去します． |
| lstrip_ow | 文字列の先頭にある半角スペースとタブ文字を除去します．```_ow``` は overwrite の意味で，引数に結果を上書きします． |
| rstrip    | 文字列の末尾にある半角スペースとタブ文字を除去します． |
| rstrip_ow | 文字列の末尾にある半角スペースとタブ文字を除去します．```_ow``` は overwrite の意味で，引数に結果を上書きします． |
| strip     | 文字列の先頭と末尾にある半角スペースとタブ文字を除去します． |
| strip_ow  | 文字列の先頭と末尾にある半角スペースとタブ文字を除去します．```_ow``` は overwrite の意味で，引数に結果を上書きします． |

- 文字列の比較．引数の型の違いにより複数定義されている．

| 名前 | 説明 |
| --- | --- |
| strcmp | 入力引数に与えられる 2 つの文字列を比較し，等しい場合は true を，それ以外は false を返す． |

## Usage

## Others
- Implementation: [sstd/src/time.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/time.hpp)
- Test code: [test/time.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/time.hpp) (Not implemented yet)

