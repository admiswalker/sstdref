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
    
    template <typename T> inline void           sort     (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end());             }                    // Ascending: 昇順: 0, 1, 2, ...
    template <typename T> inline std::vector<T> sorted   (const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
    template <typename T> inline std::vector<T> sorted   (      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end()); return rhs; }                    // Ascending: 昇順: 0, 1, 2, ...
    template <typename T> inline void           sort_gr  (      std::vector<T>&  rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>());             } // Descending: 降順: 9, 8, 7, ...
    template <typename T> inline std::vector<T> sorted_gr(const std::vector<T>&  rhs_in){ std::vector<T> rhs=rhs_in; std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...
    template <typename T> inline std::vector<T> sorted_gr(      std::vector<T>&& rhs   ){                            std::sort(rhs.begin(), rhs.end(), std::greater<T>()); return rhs; } // Descending: 降順: 9, 8, 7, ...
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------
    
    template <typename T> std::vector<T> nonzero(const std::vector<T>& rhs);
//  template <typename T> void padding (std::vector<T>& vecLhs, std::vector<T>& vecRhs); // <--> sstd::suppress();
//  template <typename T> void suppress(std::vector<T>& vecLhs, std::vector<T>& vecRhs); // <--> sstd::padding(); or zfill
    template <typename... Args> void suppress(Args&... args);
}
```


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
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<double> v_base = {-1,-5,2,-3,3,4,-2,0,1,-4};
    
    sstd::printn( sstd::sorted( v_base )    );
    sstd::printn( sstd::sorted_gr( v_base ) );
    printf("\n");
    
    std::vector<double> v = v_base;
    sstd::sort( v );
    sstd::printn( v );
    
    std::vector<double> v_gr = v_base;
    sstd::sort_gr( v_gr );
    sstd::printn( v_gr );
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
