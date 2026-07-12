# str2val
## Abstract
`str2val.hpp` / `str2val.cpp` contain functions to convert `std::string` type to `T` type.
`str2val.hpp` / `str2val.cpp` は，文字列を適切な型に変換する関数を収録している．

## Header file
```cpp
namespace sstd{
    bool str2val(                 bool   & return_val, const                    char*  s);
    bool str2val(                 char   & return_val, const                    char*  s);
    bool str2val(                  int8  & return_val, const                    char*  s);
    bool str2val(                  int16 & return_val, const                    char*  s);
    bool str2val(                  int32 & return_val, const                    char*  s);
    bool str2val(                  int64 & return_val, const                    char*  s);
    bool str2val(                 uint8  & return_val, const                    char*  s);
    bool str2val(                 uint16 & return_val, const                    char*  s);
    bool str2val(                 uint32 & return_val, const                    char*  s);
    bool str2val(                 uint64 & return_val, const                    char*  s);
    bool str2val(                  float & return_val, const                    char*  s);
    bool str2val(                 double & return_val, const                    char*  s);
    bool str2val(            std::string & return_val, const                    char*  s);

    bool str2val(                 bool   & return_val, const             std::string & s);
    bool str2val(                 char   & return_val, const             std::string & s);
    bool str2val(                  int8  & return_val, const             std::string & s);
    bool str2val(                  int16 & return_val, const             std::string & s);
    bool str2val(                  int32 & return_val, const             std::string & s);
    bool str2val(                  int64 & return_val, const             std::string & s);
    bool str2val(                 uint8  & return_val, const             std::string & s);
    bool str2val(                 uint16 & return_val, const             std::string & s);
    bool str2val(                 uint32 & return_val, const             std::string & s);
    bool str2val(                 uint64 & return_val, const             std::string & s);
    bool str2val(                  float & return_val, const             std::string & s);
    bool str2val(                 double & return_val, const             std::string & s);
    bool str2val(            std::string & return_val, const             std::string & s);

    bool str2val(                 bool   & return_val, const std::vector<std::string>& v);
    bool str2val(                 char   & return_val, const std::vector<std::string>& v);
    bool str2val(                  int8  & return_val, const std::vector<std::string>& v);
    bool str2val(                  int16 & return_val, const std::vector<std::string>& v);
    bool str2val(                  int32 & return_val, const std::vector<std::string>& v);
    bool str2val(                  int64 & return_val, const std::vector<std::string>& v);
    bool str2val(                 uint8  & return_val, const std::vector<std::string>& v);
    bool str2val(                 uint16 & return_val, const std::vector<std::string>& v);
    bool str2val(                 uint32 & return_val, const std::vector<std::string>& v);
    bool str2val(                 uint64 & return_val, const std::vector<std::string>& v);
    bool str2val(                 float  & return_val, const std::vector<std::string>& v);
    bool str2val(                 double & return_val, const std::vector<std::string>& v);
    bool str2val(            std::string & return_val, const std::vector<std::string>& v);

    bool str2val(std::vector<     bool  >& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     char  >& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<      int8 >& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<      int16>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<      int32>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<      int64>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     uint8 >& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     uint16>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     uint32>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     uint64>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     float >& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<     double>& return_val, const std::vector<std::string>& v);
    bool str2val(std::vector<std::string>& return_val, const std::vector<std::string>& v);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| str2val(    T&,   const    C*/S& ) | converts the `std::string` type into `T` type from 2nd arg to 1st arg. In case of error, `false` is returned. <br>第 2 引数に `std::string` で与えられた文字列を，`T` 型に変換して第 1 引数に返します．エラーの場合は `false` を返します． |
| str2val(    T&,   const vec<S\>& ) | converts the `std::vector<std::string>` type into `T` type from 2nd arg to 1st arg. In case of error, `false` is returned. This function expects that the number of elements in `std::vector<std::string>` type at 2nd arg is `1`. If the number of element is not `1`, `false` is returned. <br>第 2 引数に `std::vector<std::string>` で与えられた文字列を，第 1 引数に `T` 型で返します．エラーの場合は `false` を返します．この関数は第 2 引数の `std::vector<std::string>` の要素数が 1 であることを前提としており，数が異なる場合は `false` を返します． |
| str2val(vec<T\>&, const vec<S\>& ) | converts the `std::vector<std::string>` type into `std::vector<T>` type from 2nd arg to 1st arg. In case of error, `false` is returned. <br>第 2 引数に `std::vector<std::string>` で与えられた文字列を，第 1 引数に `std::vector<T>` 型で返します．エラーの場合は `false` を返します． |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    int i1=0;
    bool res1 = sstd::str2val(i1, "12");
    sstd::printn(res1);
    sstd::printn(i1);
    printf("\n");
    
    int i2=0;
    bool res2 = sstd::str2val(i2, std::vector<std::string>({"123"}));
    sstd::printn(res2);
    sstd::printn(i2);
    printf("\n");
    
    std::vector<int> v3;
    bool res3 = sstd::str2val(v3, std::vector<std::string>({"12", "123", "1234"}));
    sstd::printn(res3);
    sstd::printn(v3);
    printf("\n");
    
    // ERROR case
    int i_e1=0;
    bool res_e1 = sstd::str2val(i_e1, "invalid-integer");
    sstd::printn(res_e1);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix

## Implementation
- Source: [sstd/src/cast/str2val.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/cast/str2val.cpp)
- Header: [sstd/src/cast/str2val.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/cast/str2val.hpp)
- Test: [test/cast/str2val.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/cast/str2val.hpp)

