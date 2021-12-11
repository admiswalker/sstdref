title: Ope. Exp. for std::vector&lt;T&gt;
# Operator expansions for std::vector&lt;T&gt;
## Abstract
Operator definitions on SSTD. These definitions are read by `#include <sstd/sstd.hpp>`.  
SSTD における演算子の定義．`#include <sstd/sstd.hpp>` により定義が読み込まれる．

## Header file
```cpp
namespace sstd_stdVecEx{
    // operators for mathematics
    SSTD_DEF_stdVecEx_defInNamespace   (add   ); // +
    SSTD_DEF_stdVecEx_defInNamespace_eq(add_eq); // +=
    SSTD_DEF_stdVecEx_defInNamespace   (sub   ); // -
    SSTD_DEF_stdVecEx_defInNamespace_eq(sub_eq); // -=
    SSTD_DEF_stdVecEx_defInNamespace   (mul   ); // *
    SSTD_DEF_stdVecEx_defInNamespace_eq(mul_eq); // *=
    SSTD_DEF_stdVecEx_defInNamespace   (div   ); // /
    SSTD_DEF_stdVecEx_defInNamespace_eq(div_eq); // /=
    SSTD_DEF_stdVecEx_defInNamespace   (mod   ); // %
    SSTD_DEF_stdVecEx_defInNamespace_eq(mod_eq); // %=
    SSTD_DEF_stdVecEx_defInNamespace   (pow   ); // ^
    SSTD_DEF_stdVecEx_defInNamespace_eq(pow_eq); // ^=
    
    // operators for std::vector
    SSTD_DEF_stdVecEx_defInNamespace   (push_front   ); // >>
    SSTD_DEF_stdVecEx_defInNamespace_eq(push_front_eq); // >>=
    SSTD_DEF_stdVecEx_defInNamespace   (push_back    ); // <<
    SSTD_DEF_stdVecEx_defInNamespace_eq(push_back_eq ); // <<=
}
```

## Usage
### Ope. * and *=
#### vector × scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v = {1, 2, 3};
    sstd::printn( v * 2 );
    
    v *= 3;
    sstd::printn( v );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### vector × vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {2, 3, 4};
    sstd::printn( v1 * v2 );
    
    v1 *= v2;
    sstd::printn( v1 );
    sstd::printn( v2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### any depth vector × scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::vector<std::vector<int>>> v = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    sstd::printn( v * 2 );
    
    v *= 3;
    sstd::printn( v );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### any depth vector × vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::vector<std::vector<int>>> v1 = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
    std::vector<std::vector<std::vector<int>>> v2 = {{{9, 10}, {11, 12}}, {{13, 14}, {15, 16}}};
    sstd::printn( v1 * v2 );
    
    v1 *= v2;
    sstd::printn( v1 );
    sstd::printn( v2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Linking <<
#### vector << scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v = {1, 2, 3};
    int s = 4;
    sstd::printn( v << s );
    sstd::printn( v );
    sstd::printn( s );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### vector << vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    sstd::printn( v1 << v2 );
    sstd::printn( v1 );
    sstd::printn( v2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### push_back()
#### vector <<= scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v;
    v <<= 1; // same as a "v.push_back(1);"
    v <<= 2; // same as a "v.push_back(2);"
    v <<= 3; // same as a "v.push_back(3);"
    
    sstd::printn( v );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### vector <<= vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    v1 <<= v2;
    
    sstd::printn( v1 );
    sstd::printn( v2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Linking >>
#### vector >> scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v = {1, 2, 3};
    int s = 0;
    sstd::printn( v >> s );
    sstd::printn( v );
    sstd::printn( s );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### vector >> vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {-2, -1, 0};
    sstd::printn( v1 >> v2 );
    sstd::printn( v1 );
    sstd::printn( v2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### push_front()
#### vector >>= scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v = {1, 2, 3};
    v >>= 0;
    
    sstd::printn( v );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### vector >>= vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {-2, -1, 0};
    v1 >>= v2;
    
    sstd::printn( v1 );
    sstd::printn( v2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Header: [sstd/src/vector/stdVector_expansion.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/vector/stdVector_expansion.hpp)
- Test: [test/vector_stdVector_expansion.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/vector_stdVector_expansion.hpp)

