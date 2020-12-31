# print / printn
## Abstract
```print``` and ```printn``` print values of variables.  
```print``` と ```printn``` は変数の値を出力します．

## Header file
```cpp
namespace sstd{
    void print(const bool rhs);
    void print(const char rhs);
    void print(const int8 rhs);
    void print(const int16 rhs);
    void print(const int32 rhs);
    void print(const int64 rhs);
    void print(const uint8 rhs);
    void print(const uint16 rhs);
    void print(const uint32 rhs);
    void print(const uint64 rhs);
    void print(const float rhs);
    void print(const double rhs);
    void print(const char* rhs);
    void print(const std::string& rhs);
    
    void print(const std::vector<bool>& rhs);
    void print(const std::vector<char>& rhs);  // 文字として表示 printf("%c", rhs[i]);
    void print(const std::vector<int8>& rhs);
    void print(const std::vector<int16>& rhs);
    void print(const std::vector<int32>& rhs);
    void print(const std::vector<int64>& rhs);
    void print(const std::vector<uint8>& rhs);
    void print(const std::vector<uint16>& rhs);
    void print(const std::vector<uint32>& rhs);
    void print(const std::vector<uint64>& rhs);
    void print(const std::vector<float>& rhs);
    void print(const std::vector<double>& rhs);
    void print(const std::vector<std::string>& rhs);
    
    void print(const std::vector<std::vector<bool>>& rhs);
    void print(const std::vector<std::vector<char>>& rhs);  // 文字として表示 printf("%c", rhs[i]);
    void print(const std::vector<std::vector<int8>>& rhs);
    void print(const std::vector<std::vector<int16>>& rhs);
    void print(const std::vector<std::vector<int32>>& rhs);
    void print(const std::vector<std::vector<int64>>& rhs);
    void print(const std::vector<std::vector<uint8>>& rhs);
    void print(const std::vector<std::vector<uint16>>& rhs);
    void print(const std::vector<std::vector<uint32>>& rhs);
    void print(const std::vector<std::vector<uint64>>& rhs);
    void print(const std::vector<std::vector<float>>& rhs);
    void print(const std::vector<std::vector<double>>& rhs);
    void print(const std::vector<std::vector<std::string>>& rhs);
    
    //---
    
    void for_printn(bool rhs);
    void for_printn(char rhs);
    void for_printn(int8 rhs);
    void for_printn(int16 rhs);
    void for_printn(int32 rhs);
    void for_printn(int64 rhs);
    void for_printn(uint8 rhs);
    void for_printn(uint16 rhs);
    void for_printn(uint32 rhs);
    void for_printn(uint64 rhs);
    void for_printn(float rhs);
    void for_printn(double rhs);
    void for_printn(const char* rhs);
    void for_printn(const std::string& rhs);
    
    void for_printn(const std::vector<bool>& rhs);
    void for_printn(const std::vector<char>& rhs);  // 文字として表示 for_printnf("%c", rhs[i]);
    void for_printn(const std::vector<int8>& rhs);
    void for_printn(const std::vector<int16>& rhs);
    void for_printn(const std::vector<int32>& rhs);
    void for_printn(const std::vector<int64>& rhs);
    void for_printn(const std::vector<uint8>& rhs);
    void for_printn(const std::vector<uint16>& rhs);
    void for_printn(const std::vector<uint32>& rhs);
    void for_printn(const std::vector<uint64>& rhs);
    void for_printn(const std::vector<float>& rhs);
    void for_printn(const std::vector<double>& rhs);
    void for_printn(const std::vector<std::string>& rhs);
    
    void for_printn(const std::vector<std::vector<bool>>& rhs);
    void for_printn(const std::vector<std::vector<char>>& rhs);  // 文字として表示 for_printnf("%c", rhs[i]);
    void for_printn(const std::vector<std::vector<int8>>& rhs);
    void for_printn(const std::vector<std::vector<int16>>& rhs);
    void for_printn(const std::vector<std::vector<int32>>& rhs);
    void for_printn(const std::vector<std::vector<int64>>& rhs);
    void for_printn(const std::vector<std::vector<uint8>>& rhs);
    void for_printn(const std::vector<std::vector<uint16>>& rhs);
    void for_printn(const std::vector<std::vector<uint32>>& rhs);
    void for_printn(const std::vector<std::vector<uint64>>& rhs);
    void for_printn(const std::vector<std::vector<float>>& rhs);
    void for_printn(const std::vector<std::vector<double>>& rhs);
    void for_printn(const std::vector<std::vector<std::string>>& rhs);
}


namespace sstd{
    inline void printn_dummy(){}
    
    inline void printn(...){}
    inline void printn_all(...){}
}

#define printn(var) printn_dummy();{printf("%s", #var);sstd::for_printn(var);}
#define printn_all(var) printn_dummy();{printf("%s(%d): %s", __func__, __LINE__, #var);sstd::for_printn(var);}
#define printn_fflv(var) printn_dummy();{printf("%s: %s(%d): %s", __FILE__, __func__, __LINE__, #var);sstd::for_printn(var);}
```

## Usage
- input
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

    std::vector<std::string> vS = {"a", "b", "c"};
    sstd::printn(vS);
    std::vector<std::vector<std::string>> vvS = {{"a", "b", "c"}, {"d", "e", "f"}};
    sstd::printn(vvS);
    printf("\n");

    sstd::mat_r<double> m = {{1,2,3}, {4,5,6}, {7,8,9}};
    sstd::printn(m);
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/print.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print.cpp)
- Header: [sstd/src/print.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print.hpp)
- Test: [test/print_printn_printn_all.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/print_printn_printn_all.hpp)
