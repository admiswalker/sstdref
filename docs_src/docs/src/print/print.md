# print / printn
## Abstract
`print()`, `printn()`, `printn_all()` and `printn_fflv()` print values of variable.  
`printn()`, `printn_all()` and `printn_fflv()` are macro functions and able to apply variables can print by `for_printn()`.

`print()`, `printn()`, `printn_all()` and `printn_fflv()` は変数の値を表示する．  
`printn()`, `printn_all()` and `printn_fflv()` はマクロ関数で，`for_printn()` で表示できる変数に適用できる．

| name of macro function | descriptions |
| ---------------------- | ------------ |
| `print()`              | print values of variable. <br>変数の値を出力します． |
| `printn()`             | print values of variable with variable name. <br>変数の値を，変数名を付与して出力します． |
| `printn_all()`         | print values of variable with variable name, function name and function line number. <br>変数の値を，変数名と関数名，関数の行番号を付与して出力します． |
| `printn_fflv()`        | print values of variable with variable name, function name, function line number, path to the function and implemented file name. <br>変数の値を，変数名と関数名，関数の行番号，実装のファイルのファイル名とパス，を付与して出力します． |


## Header file
```cpp
namespace sstd{
    void print(const  void* rhs);
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
    template <typename T_lhs, typename T_rhs>
    void print(const std::unordered_map<T_lhs, T_rhs>& rhs);
    
    void for_printn( void* rhs);
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
    template <typename T_lhs, typename T_rhs>
    void for_printn(const std::unordered_map<T_lhs, T_rhs>& rhs);

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
### print(), printn(), printn_all(), printn_fflv()
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
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### print void* (pointer) type
#### Normal case
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    int num = 123;
    sstd::printn(&num);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### char* case
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    const char *pC = "abc";
    sstd::printn((void*)pC); // To print a pointer address, sstd::print requires to cast char* to void*.
    
    sstd::printn(pC); // when the case not cast to void*, sstd::print treats the variable as a string.
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### print bool type
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    bool TF_t = true;  sstd::printn(TF_t);
    bool TF_f = false; sstd::printn(TF_f);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### print std::vector&lt;T&gt; type
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> vS = {"a", "b", "c"};
    sstd::printn(vS);
    std::vector<std::vector<std::string>> vvS = {{"a", "b", "c"}, {"d", "e", "f"}};
    sstd::printn(vvS);
    printf("\n");

    // any depth vector<T>. T is bool, char, (u)int8-16-32-64, float, double, char* and std::string.
    std::vector<std::vector<std::vector<std::vector<int>>>> v4_int = {{{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}}, {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}}};
    sstd::printn(v4_int);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### print std::unordered_map&lt;T_lhs, T_rhs&gt; type
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::unordered_map<std::string, std::vector<uint>> table;
    table["abc"] = {123, 456};
    table["def"] = {456, 789};
    sstd::printn(table);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### print sstd::mat_r&lt;T&gt; type
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m = {{1,2,3}, {4,5,6}, {7,8,9}};
    sstd::printn(m);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/print/print.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print/print.cpp)
- Header: [sstd/src/print/print.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print/print.hpp)
- Test: [test/src_test/print/print_printn_printn_all.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/print/print_printn_printn_all.cpp)
