# print / printn
## Abstract
`print` and `printn` print values of variables.  
`print` と `printn` は変数の値を出力します．

## Header file
```cpp
namespace sstd{
    void print(const  bool  rhs);
    void print(const  char  rhs);
    void print(const  int8  rhs);
    void print(const  int16 rhs);
    void print(const  int32 rhs);
    void print(const  int64 rhs);
    void print(const uint8  rhs);
    void print(const uint16 rhs);
    void print(const uint32 rhs);
    void print(const uint64 rhs);
    void print(const float  rhs);
    void print(const double rhs);
    void print(const        char* rhs);
    void print(const std::string& rhs);
    template <typename T>
    void print(const std::vector<T>& rhs);
    
    void for_printn( bool  rhs);
    void for_printn( char  rhs);
    void for_printn( int8  rhs);
    void for_printn( int16 rhs);
    void for_printn( int32 rhs);
    void for_printn( int64 rhs);
    void for_printn(uint8  rhs);
    void for_printn(uint16 rhs);
    void for_printn(uint32 rhs);
    void for_printn(uint64 rhs);
    void for_printn( float rhs);
    void for_printn(double rhs);
    void for_printn(const        char* rhs);
    void for_printn(const std::string& rhs);
    template <typename T>
    void for_printn(const std::vector<T>& rhs);

    //---

    // for #define
    inline void printn_dummy(){}
    inline void printn(...){}
    inline void printn_all(...){}
}

#define printn(var) printn_dummy();{printf("%s", #var);sstd::for_printn(var);}
#define printn_all(var) printn_dummy();{printf("%s(%d): %s", __func__, __LINE__, #var);sstd::for_printn(var);}
#define printn_fflv(var) printn_dummy();{printf("%s: %s(%d): %s", __FILE__, __func__, __LINE__, #var);sstd::for_printn(var);}
```

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    int i = 0;
    sstd::print(i);
    sstd::printn(i);
    sstd::printn_all(i);
    sstd::printn_fflv(i);
    printf("\n");
    
    bool TF_t = true;  sstd::printn(TF_t);
    bool TF_f = false; sstd::printn(TF_f);
    printf("\n");

    std::vector<char> vC = {'a', 'b', 'c'};
    sstd::printn(vC);
    printf("\n");
    
    std::vector<std::string> vS = {"a", "b", "c"};
    sstd::printn(vS);
    std::vector<std::vector<std::string>> vvS = {{"a", "b", "c"}, {"d", "e", "f"}};
    sstd::printn(vvS);
    printf("\n");

    // any depth vector<T>. T is bool, char, (u)int8-16-32-64, float, double, char* and std::string.
    std::vector<std::vector<std::vector<std::vector<int>>>> v4_int = {{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}}, {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    sstd::printn(v4_int);
    printf("\n");
    
    sstd::mat_r<double> m = {{1,2,3}, {4,5,6}, {7,8,9}};
    sstd::printn(m);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/print.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print.cpp)
- Header: [sstd/src/print.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print.hpp)
- Test: [test/print_printn_printn_all.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/print_printn_printn_all.hpp)
