# math
## Abstract
`math.hpp` contains functions for mathmatical and statistical calculations.  
`math.hpp` は数学・統計計算用の関数を収録します．

## Header file
```cpp
namespace sstd{
    float  round2even(float n);
    double round2even(double n);

    float  round2odd(float n);
    double round2odd(double n);
    
    template<typename T> T sum(const std::vector<T>& rhs);
    template<typename T> T sum(const std::vector<T>& rhs, uint a, uint b);
    template<class Itr> typename std::iterator_traits<Itr>::value_type sum(const Itr first, const Itr last);
    
    // using Pairwise summation algorithm.
    float  sum    (const std::vector<float>::iterator first, const std::vector<float>::iterator last);
    float  sum    (const std::vector<float>& rhs, uint a, uint b); // 配列の a 番目から b 番目までの合計. sum of the a th to b th of array.
    float  sum    (const std::vector<float>& rhs);
    float  sum_abs(const std::vector<float>& rhs);
    float  ave    (const std::vector<float>& rhs); // 平均値: average
    float  med    (      std::vector<float>  rhs); // 中央値: median // copy rhs // If rhs.size () is even, average of the two median values is returned.
//  float  mod    (const std::vector<float>& rhs); // 最頻値: mode
    float  var    (const std::vector<float>& rhs); // 不偏分散/標本分散 (variance): u^2 = (1/(n-1))*Σ(x_i-μ)^2
    float  var_p  (const std::vector<float>& rhs); // 母分散 (variance population): σ^2 = (1/n)*Σ(x_i-μ)^2
    float  stdev  (const std::vector<float>& rhs); // 標本標準偏差 (sample standard deviation): u = SQRT( (1/(n-1))*Σ(x_i-μ)^2 )
    float  stdev_p(const std::vector<float>& rhs); // 標準偏差 (standard deviation): σ = SQRT( (1/n)*Σ(x_i-μ)^2 )
    
    double sum    (const std::vector<double>::iterator first, const std::vector<double>::iterator last);
    double sum    (const std::vector<double>& rhs, uint a, uint b); // 配列の a 番目から b 番目までの合計. sum of the a th to b th of array.
    double sum    (const std::vector<double>& rhs);
    double sum_abs(const std::vector<double>& rhs);
    double ave    (const std::vector<double>& rhs); // 平均値: average
    double med    (      std::vector<double>  rhs); // 中央値: median // copy rhs // If rhs.size () is even, average of the two median values is returned.
//  double mod    (const std::vector<double>& rhs); // 最頻値: mode
    double var    (const std::vector<double>& rhs); // 不偏分散/標本分散 (variance): u^2 = (1/(n-1))*Σ(x_i-μ)^2
    double var_p  (const std::vector<double>& rhs); // 母分散 (variance population): σ^2 = (1/n)*Σ(x_i-μ)^2
    double stdev  (const std::vector<double>& rhs); // 標本標準偏差 (sample standard deviation): u = SQRT( (1/(n-1))*Σ(x_i-μ)^2 )
    double stdev_p(const std::vector<double>& rhs); // 標準偏差 (standard deviation): σ = SQRT( (1/n)*Σ(x_i-μ)^2 )
    
    // K: using Kahan summation algorithm
    float  sumK    (const std::vector<float>& rhs, uint a, uint b); // 配列の a 番目から b 番目までの合計. sum of the a th to b th of array.
    float  sumK    (const std::vector<float>& rhs);
    float  sumK_abs(const std::vector<float>& rhs);
    float  aveK    (const std::vector<float>& rhs);           // 平均値: average
    float  aveK    (const std::vector<float>& rhs, uint num); // 平均値: average in the first num elements.
    float  varK    (const std::vector<float>& rhs); // 不偏分散/標本分散 (variance): u^2 = (1/(n-1))*Σ(x_i-μ)^2
    float  varK_p  (const std::vector<float>& rhs); // 母分散 (variance population): σ^2 = (1/n)*Σ(x_i-μ)^2
    float  stdevK  (const std::vector<float>& rhs); // 標本標準偏差 (sample standard deviation): u = SQRT( (1/(n-1))*Σ(x_i-μ)^2 )
    float  stdevK_p(const std::vector<float>& rhs); // 標準偏差 (standard deviation): σ = SQRT( (1/n)*Σ(x_i-μ)^2 )
    
    double sumK    (const std::vector<double>& rhs);
    double sumK    (const std::vector<double>& rhs, uint a, uint b); // 配列の a 番目から b 番目までの合計. sum of the a th to b th of array.
    double sumK_abs(const std::vector<double>& rhs);
    double aveK    (const std::vector<double>& rhs);           // 平均値: average
    double aveK    (const std::vector<double>& rhs, uint num); // 平均値: average in the first num elements.
    double varK    (const std::vector<double>& rhs); // 不偏分散/標本分散 (variance): u^2 = (1/(n-1))*Σ(x_i-μ)^2
    double varK_p  (const std::vector<double>& rhs); // 母分散 (variance population): σ^2 = (1/n)*Σ(x_i-μ)^2
    double stdevK  (const std::vector<double>& rhs); // 標本標準偏差 (sample standard deviation): u = SQRT( (1/(n-1))*Σ(x_i-μ)^2 )
    double stdevK_p(const std::vector<double>& rhs); // 標準偏差 (standard deviation): σ = SQRT( (1/n)*Σ(x_i-μ)^2 )
    
    std::vector<uint64> prime(uint64 rhs);                                  // get a list of prime number under rhs.
    struct fact{
        uint64 prime;
        uint64 num;
    };
    std::vector<struct fact> factor(uint64 rhs);                            // get a list of prime factorization
    std::vector<uint64> divisor(const std::vector<struct sstd::fact>& rhs); // get a list of all divisors
    std::vector<uint64> divisor(uint64 rhs);                                // get a list of all of the divisors.

    uint8  pow(const uint8 & base, const uint8 & exp);
    uint16 pow(const uint16& base, const uint16& exp);
    uint32 pow(const uint32& base, const uint32& exp);
    uint64 pow(const uint64& base, const uint64& exp);
     float pow(const  float& base, const  float& exp);
    double pow(const double& base, const double& exp);

    //-----------------------------------------------------------------------------------------------------------------------------------------------
    
    template<typename T> inline T min    (const std::vector<T>& rhs);
    template<typename T> inline T min_abs(const std::vector<T>& rhs);
    template<typename T> inline T max    (const std::vector<T>& rhs);
    template<typename T> inline T max_abs(const std::vector<T>& rhs);
    
    template<typename T> inline T min    (const sstd::mat_c<T>& rhs);
    template<typename T> inline T min_abs(const sstd::mat_c<T>& rhs);
    template<typename T> inline T max    (const sstd::mat_c<T>& rhs);
    template<typename T> inline T max_abs(const sstd::mat_c<T>& rhs);
    
    template<typename T> inline T min    (const sstd::mat_r<T>& rhs);
    template<typename T> inline T min_abs(const sstd::mat_r<T>& rhs);
    template<typename T> inline T max    (const sstd::mat_r<T>& rhs);
    template<typename T> inline T max_abs(const sstd::mat_r<T>& rhs);
    
    template<typename T> inline T min(T&& lhs, T&& rhs);
    template<typename T> inline T min(T&& head1, T&& head2, T&& tail);
    template<typename Head, typename... Tail>
    inline Head min(Head&& head1, Head&& head2, Tail&&... tail);
    
    template<typename T> inline T max(T&& lhs, T&& rhs);
    template<typename T> inline T max(T&& head1, T&& head2, T&& tail);
    template<typename Head, typename... Tail>
    inline Head max(Head&& head1, Head&& head2, Tail&&... tail);
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    
    template<typename T> uint argmin    (const std::vector<T>& rhs);
    template<typename T> uint argmin_abs(const std::vector<T>& rhs);
    template<typename T> uint argmax    (const std::vector<T>& rhs);
    template<typename T> uint argmax_abs(const std::vector<T>& rhs);
    
    template<typename T> uint argmin    (const sstd::mat_c<T>& rhs);
    template<typename T> uint argmin_abs(const sstd::mat_c<T>& rhs);
    template<typename T> uint argmax    (const sstd::mat_c<T>& rhs);
    template<typename T> uint argmax_abs(const sstd::mat_c<T>& rhs);
    
    template<typename T> uint argmin    (const sstd::mat_r<T>& rhs);
    template<typename T> uint argmin_abs(const sstd::mat_r<T>& rhs);
    template<typename T> uint argmax    (const sstd::mat_r<T>& rhs);
    template<typename T> uint argmax_abs(const sstd::mat_r<T>& rhs);
    /*
    // TODO: argmin
    // TODO: argmax
    
    template<typename T> std::tuple<uint,uint> argminXY    (const sstd::mat_c<T>& rhs);
    template<typename T> std::tuple<uint,uint> argminXY_abs(const sstd::mat_c<T>& rhs);
    template<typename T> std::tuple<uint,uint> argmaxXY    (const sstd::mat_c<T>& rhs);
    template<typename T> std::tuple<uint,uint> argmaxXY_abs(const sstd::mat_c<T>& rhs);
    
    template<typename T> std::tuple<uint,uint> argminXY    (const sstd::mat_r<T>& rhs);
    template<typename T> std::tuple<uint,uint> argminXY_abs(const sstd::mat_r<T>& rhs);
    template<typename T> std::tuple<uint,uint> argmaxXY    (const sstd::mat_r<T>& rhs);
    template<typename T> std::tuple<uint,uint> argmaxXY_abs(const sstd::mat_r<T>& rhs);
    //*/
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    // binary search
    
    template<typename T> T       nearest_down(const std::vector<T>& v, const T& value);
    template<typename T> T       nearest_up  (const std::vector<T>& v, const T& value);
    template<typename T> uint argnearest_down(const std::vector<T>& v, const T& value);
    template<typename T> uint argnearest_up  (const std::vector<T>& v, const T& value);
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    // sort
    
    template <typename T> inline void           sort     (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end());             }                    // Ascending: 昇順: 0, 1, 2, ...
    template <typename T> inline std::vector<T> sorted   (const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
    template <typename T> inline std::vector<T> sorted   (      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
    template <typename T> inline void           sort_gr  (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             } // Descending: 降順: 9, 8, 7, ...
    template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...
    template <typename T> inline std::vector<T> sorted_gr(      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    // sort for multiple vector
    
    template<typename Head, typename... Tail> inline void sort   (Head&& head, Tail&&... tail); // Ascending: 昇順: 0, 1, 2, ...
    template<typename Head, typename... Tail> inline void sort_gr(Head&& head, Tail&&... tail); // Descending: 降順: 9, 8, 7, ...
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    
    template <typename T> std::vector<T> nonzero(const std::vector<T>& rhs);
//  template <typename T> void padding (std::vector<T>& vecLhs, std::vector<T>& vecRhs); // <--> sstd::suppress();
//  template <typename T> void suppress(std::vector<T>& vecLhs, std::vector<T>& vecRhs); // <--> sstd::padding(); or zfill
    template <typename... Args> void suppress(Args&... args);
}
```

## Description
### Numerical calculation
| Function name | Description |
| ------------- | ----------- |
| round2even()  | <br> |
| round2odd()  | <br> |
| sum()  | <br> |
| sum_abs()  | <br> |
| ave()  | <br> |
| med()  | <br> |
| var()  | <br> |
| var_p()  | <br> |
| stdev()  | <br> |
| stdev_p()  | <br> |
| sumK()  | <br> |
| sumK_abs()  | <br> |
| aveK()  | <br> |
| varK()  | <br> |
| varK_p()  | <br> |
| stdevK()  | <br> |
| stdevK_p()  | <br> |
| pow()  | <br> |

### prime number calculation
| Function name | Description |
| ------------- | ----------- |
| prime()  | <br> |
| factor()  | <br> |
| divisor()  | <br> |

### search
| Function name | Description |
| ------------- | ----------- |
| min()         | returns minimum value of given arg(s). min() can specifies multiple args while args have the same type and is defined < operator.<br>与えられた値の内，最も小さい値を返します．同一型で operator < が定義されている型であれば，複数の引数を指定できます． |
| min_abs()     | <br> |
| max()         | returns minimum value of given arg(s). min() can specifies multiple args while args have the same type and is defined < operator.<br>与えられた値の内，最も大きい値を返します．同一型で operator < が定義されている型であれば，複数の引数を指定できます． |
| max_abs()     | <br> |
| argmin()      | <br> |
| argmin_abs()  | <br> |
| argmax()      | <br> |
| argmax_abs()  | <br> |
| nearest_down()    | <br> |
| nearest_up()  | <br> |
| argnearest_down() | <br> |
| argnearest_up()   | <br> |

### sort
| Function name | Description |
| ------------- | ----------- |
| sort()        | sorts arg(s) value directly in ascending order. When multiple `std::vector<T>`s are specified to arg, all `std::vector<T>`s will be sorted according to the 1st arg. There is no limit to the number or type of `std::vector<T>` specified in the argument.<br>引数の値を直接ソートする．値は昇順にソートされる．引数に `std::vector<T>` が複数与えられた場合は，第１引数の順序に従って他の引数をソートする．引数に指定する `std::vector<T>` の数や型に制限はない． |
| sorted()      | returns sorted value of arg(s) in ascending order, and arg(s) will not changed.<br>ソート結果を昇順で返す．引数は変更されない． |
| sort_gr()     | sorts arg(s) value directly in descending order. When multiple `std::vector<T>`s are specified to arg, all `std::vector<T>`s will be sorted according to the 1st arg. There is no limit to the number or type of `std::vector<T>` specified in the argument.<br>引数の値を直接ソートする．値は降順にソートされる．引数に `std::vector<T>` が複数与えられた場合は，第１引数の順序に従って他の引数をソートする．引数に指定する `std::vector<T>` の数や型に制限はない． |
| sorted_gr()   | returns sorted value of arg(s) in descending order, and arg(s) will not changed.<br>ソート結果を降順で返す．引数は変更されない． |

### preprocess
| Function name | Description |
| ------------- | ----------- |
| nonzero()  | <br> |
| suppress()  | <br> |


## Usage
### Rounding
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::round2even(1.5) );
    sstd::printn( sstd::round2even(2.5) );
    
    sstd::printn( sstd::round2odd(1.5) );
    sstd::printn( sstd::round2odd(2.5) );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### Statistical processing
#### sum(), sum_abs(), ave(), med(), var(), var_p(), min(), min_abs(), max(), max_abs(), argmin(), argmin_abs(), argmax() and argmax_abs()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> v = {-5,-4,-3,-2,-1,0,1,2,3,4};
    sstd::printn( sstd::sum( v ) );
    sstd::printn( sstd::sum_abs( v ) );
    sstd::printn( sstd::ave( v ) );
    sstd::printn( sstd::med( v ) );
    sstd::printn( sstd::var( v ) );
    sstd::printn( sstd::var_p( v ) );
    sstd::printn( sstd::stdev( v ) );
    sstd::printn( sstd::stdev_p( v ) );
    printf("\n");
    
    sstd::printn( sstd::min( v ) );
    sstd::printn( sstd::min_abs( v ) );
    sstd::printn( sstd::max( v ) );
    sstd::printn( sstd::max_abs( v ) );
    printf("\n");
    
    sstd::printn( sstd::argmin( v ) );
    sstd::printn( sstd::argmin_abs( v ) );
    sstd::printn( sstd::argmax( v ) );
    sstd::printn( sstd::argmax_abs( v ) );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### min() and max() for equal or more than three args
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::min(-5,-4,-3,-2,-1,0,1,2,3,4) );
    sstd::printn( sstd::max(-5,-4,-3,-2,-1,0,1,2,3,4) );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Searching
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> v = {-5,-4,-3,-2,-1,0,1,2,3,4};
    sstd::printn( sstd::nearest_down(v, 0.5) );
    sstd::printn( sstd::nearest_up(v, 0.5) );
    printf("\n");
    
    sstd::printn( sstd::argnearest_down(v, 0.5) );
    sstd::printn( sstd::argnearest_up(v, 0.5) );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### Sorting
#### sort(), sort_gr()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> v_base = {-1,-5,2,-3,3,4,-2,0,1,-4};

    sstd::sort(v_base);
    sstd::printn(v_base);
    
    sstd::sort_gr(v_base);
    sstd::printn(v_base);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### sort() for multiple vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int>         v1_sorting_seed = {1, 3, 5, 2, 4};
    std::vector<std::string> v2              = {"one", "three", "five", "two", "four"};
    std::vector<std::string> v3              = {"1", "3", "5", "2", "4"};
    std::vector<std::string> v4              = {"a", "c", "e", "b", "d"};
    std::vector<std::string> v5              = {"A", "C", "E", "B", "D"};
    
    sstd::sort(v1_sorting_seed, v2, v3, v4, v5);

    sstd::printn(v1_sorting_seed);
    sstd::printn(v2);
    sstd::printn(v3);
    sstd::printn(v4);
    sstd::printn(v5);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### sort_gr() for multiple vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int>         v1_sorting_seed = {1, 3, 5, 2, 4};
    std::vector<std::string> v2              = {"one", "three", "five", "two", "four"};
    std::vector<std::string> v3              = {"1", "3", "5", "2", "4"};
    std::vector<std::string> v4              = {"a", "c", "e", "b", "d"};
    std::vector<std::string> v5              = {"A", "C", "E", "B", "D"};
    
    sstd::sort_gr(v1_sorting_seed, v2, v3, v4, v5);

    sstd::printn(v1_sorting_seed);
    sstd::printn(v2);
    sstd::printn(v3);
    sstd::printn(v4);
    sstd::printn(v5);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### sorted(), sorted_gr()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> v_base = {-1,-5,2,-3,3,4,-2,0,1,-4};
    
    sstd::printn( sstd::sorted( v_base )    );
    sstd::printn( sstd::sorted_gr( v_base ) );
    printf("\n");
    
    sstd::printn( v_base );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### Preprocessing
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> v={1,2,3,0,4};
    sstd::printn( sstd::nonzero(v) );

    // suppressing vector to the same length before 0.
    std::vector<double> in1={1,2,3,0,4};
    std::vector<double> in2={1,2,3};
    std::vector<uint>   in3={1,2,3};
    std::vector<double> in4={1,2,3,4};
    sstd::suppress(in1, in2, in3, in4);
    
    sstd::printn( in1 );
    sstd::printn( in2 );
    sstd::printn( in3 );
    sstd::printn( in4 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


## Implementation
- Source: [sstd/src/math.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/math.cpp)
- Header: [sstd/src/math.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/math.hpp)
- Test: [test/math.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/math.hpp)
