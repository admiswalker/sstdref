# itr
## Abstract
```sstd::begin()``` and ```sstd::end()``` are the definitions for SSTD iterator.  
```sstd::begin()``` と ```sstd::end()``` は SSTD のイテレータに利用するための定義です．

## Header file
```cpp
namespace sstd{
    class begin;
    class end;
}
```

## Usage
- input
```cpp
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

## Implementation
- Header: [sstd/src/itr.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/itr.hpp)

