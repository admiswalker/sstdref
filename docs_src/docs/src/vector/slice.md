# slice
## Abstract
`sstd::slice` / `sstd::slice_mv` は，Python の slice 実装を C++ 風にアレンジした sstd の独自実装です．
`sstd::slice` は要素コピーを伴う命令で，`sstd::slice_mv` は内部的に `std::move` を呼び出します．
`std::vector` に対する `slice` 操作を定義しています．

なお，`sstd::begin` および `sstd::end` は，
[src/itr.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/itr.hpp) に定義されている．

## Header file
```cpp
namespace sstd{
    sstd_vecSc::slice_i  slice(const         int val);
    sstd_vecSc::slice_u  slice(const        uint val);
    sstd_vecSc::slice_s  slice(const      size_t val);
    sstd_vecSc::slice_b  slice(const sstd::begin val);
    sstd_vecSc::slice_e  slice(const sstd::end   val);
    
    sstd_vecSc::slice_ii slice(const         int lhs, const       int rhs);
    sstd_vecSc::slice_iu slice(const         int lhs, const      uint rhs);
    sstd_vecSc::slice_is slice(const         int lhs, const    size_t rhs);
    sstd_vecSc::slice_ui slice(const        uint lhs, const       int rhs);
    sstd_vecSc::slice_uu slice(const        uint lhs, const      uint rhs);
    sstd_vecSc::slice_us slice(const        uint lhs, const    size_t rhs);
    sstd_vecSc::slice_si slice(const      size_t lhs, const       int rhs);
    sstd_vecSc::slice_su slice(const      size_t lhs, const      uint rhs);
    sstd_vecSc::slice_ss slice(const      size_t lhs, const    size_t rhs);
    
    sstd_vecSc::slice_bi slice(const sstd::begin lhs, const       int rhs);
    sstd_vecSc::slice_bu slice(const sstd::begin lhs, const      uint rhs);
    sstd_vecSc::slice_bs slice(const sstd::begin lhs, const    size_t rhs);
    sstd_vecSc::slice_ie slice(const         int lhs, const sstd::end rhs);
    sstd_vecSc::slice_ue slice(const        uint lhs, const sstd::end rhs);
    sstd_vecSc::slice_se slice(const      size_t lhs, const sstd::end rhs);
    sstd_vecSc::slice_be slice(const sstd::begin lhs, const sstd::end rhs);
    
    //---
    
    sstd_vecSc::slice_mv_i  slice_mv(const         int val);
    sstd_vecSc::slice_mv_u  slice_mv(const        uint val);
    sstd_vecSc::slice_mv_s  slice_mv(const      size_t val);
    sstd_vecSc::slice_mv_b  slice_mv(const sstd::begin val);
    sstd_vecSc::slice_mv_e  slice_mv(const sstd::end   val);
    
    sstd_vecSc::slice_mv_ii slice_mv(const         int lhs, const       int rhs);
    sstd_vecSc::slice_mv_iu slice_mv(const         int lhs, const      uint rhs);
    sstd_vecSc::slice_mv_is slice_mv(const         int lhs, const    size_t rhs);
    sstd_vecSc::slice_mv_ui slice_mv(const        uint lhs, const       int rhs);
    sstd_vecSc::slice_mv_uu slice_mv(const        uint lhs, const      uint rhs);
    sstd_vecSc::slice_mv_us slice_mv(const        uint lhs, const    size_t rhs);
    sstd_vecSc::slice_mv_si slice_mv(const      size_t lhs, const       int rhs);
    sstd_vecSc::slice_mv_su slice_mv(const      size_t lhs, const      uint rhs);
    sstd_vecSc::slice_mv_ss slice_mv(const      size_t lhs, const    size_t rhs);
    
    sstd_vecSc::slice_mv_bi slice_mv(const sstd::begin lhs, const       int rhs);
    sstd_vecSc::slice_mv_bu slice_mv(const sstd::begin lhs, const      uint rhs);
    sstd_vecSc::slice_mv_bs slice_mv(const sstd::begin lhs, const    size_t rhs);
    sstd_vecSc::slice_mv_ie slice_mv(const         int lhs, const sstd::end rhs);
    sstd_vecSc::slice_mv_ue slice_mv(const        uint lhs, const sstd::end rhs);
    sstd_vecSc::slice_mv_se slice_mv(const      size_t lhs, const sstd::end rhs);
    sstd_vecSc::slice_mv_be slice_mv(const sstd::begin lhs, const sstd::end rhs);
}
```

## Usage

### one arg (copy)
- input
```c++
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v          = {1,2,3,4,5};
    std::vector<int> v_sliced01 = v && sstd::slice(1);
    std::vector<int> v_sliced02 = v && sstd::slice(-1);
    
    sstd::printn(v);
    sstd::printn(v_sliced01);
    sstd::printn(v_sliced02);
}
```
- output
```
#mdEx: cpp example (out)
```

### two args (copy)
- input
```c++
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v        = {1,2,3,4,5};
    std::vector<int> v_sliced = v && sstd::slice(1,3);
    
    sstd::printn(v);
    sstd::printn(v_sliced);
}
```
- output
```
#mdEx: cpp example (out)
```

### begin to end (copy)
- input
```c++
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v        = {1,2,3,4,5};
    std::vector<int> v_sliced = v && sstd::slice(sstd::begin(),sstd::end());
    
    sstd::printn(v);
    sstd::printn(v_sliced);
}
```
- output
```
#mdEx: cpp example (out)
```

### one arg (move)
- input
```c++
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> v          = {"1","2","3","4","5"};
    std::vector<std::string> v_sliced01 = v && sstd::slice_mv(1);
    std::vector<std::string> v_sliced02 = v && sstd::slice_mv(-1);
    
    sstd::printn(v);
    sstd::printn(v_sliced01);
    sstd::printn(v_sliced02);
}
```
- output
```
#mdEx: cpp example (out)
```

### two args (move)
- input
```c++
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> v        = {"1","2","3","4","5"};
    std::vector<std::string> v_sliced = v && sstd::slice_mv(1,3);
    
    sstd::printn(v);
    sstd::printn(v_sliced);
}
```
- output
```
#mdEx: cpp example (out)
```

### begin to end (move)
- input
```c++
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> v        = {"1","2","3","4","5"};
    std::vector<std::string> v_sliced = v && sstd::slice_mv(sstd::begin(),sstd::end());
    
    sstd::printn(v);
    sstd::printn(v_sliced);
}
```
- output
```
#mdEx: cpp example (out)
```


## Implementation
- Header: [sstd/src/vector/slice.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/vector/slice.hpp)
- Test: [test/vector_slice.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/vector_slice.hpp)

