# duplicated
## Abstract
`duplicated.hpp` contains the functions to resolve duplicated items in the `std::vector<T>`.  
`duplicated.hpp` は，`std::vector<T>` に含まれる要素の重複を解決する処理を収録している．

## Header file
```cpp
namespace sstd{
    template<typename T>
    std::vector<std::tuple<T,uint>> duplicated_key_cnt(const std::vector<T>& v);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| duplicated_key_cnt() | aggregates duplicated elements in the `std::vector<T>` by key and returns them as a `tuple`. <br>`std::vector<T>` に重複要素して含まれる要素を key ごとに集計して `tuple` 型で返します． |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> vs = {"a", "a", "a", "x", "x", "b", "c", "d", "d"};

    std::vector<std::tuple<std::string,uint>> vDuplicated_key_cnt = sstd::duplicated_key_cnt(vs);
    sstd::sort( vDuplicated_key_cnt );
    sstd::printn( vDuplicated_key_cnt );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix
### A use case example for `sstd::duplicated_key_cnt()`
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

struct someLargeData{
    someLargeData(std::string data_in){ data=data_in; }
    ~someLargeData(){}
    
    std::string data;
    // ----------------------------------
    // -- Some large payloads are here --
    // ----------------------------------
};

int main(){
    std::vector<int> vDataIdx = { // some of the user inputting data
        3,
        0,
        1,
        2,
        3
    };

    std::vector<struct someLargeData> vData = { // internal data table
        someLargeData("Data-A"),
        someLargeData("Data-B"),
        someLargeData("Data-C"),
        someLargeData("Data-D"),
    };

    std::vector<std::tuple<int,uint>> vDuplicated_type_cnt = sstd::duplicated_key_cnt(vDataIdx);
    sstd::sort( vDuplicated_type_cnt );
    sstd::printn( vDuplicated_type_cnt );
    printf("\n");

    if(vDuplicated_type_cnt.size()==0){ return 0; /* no error */ }
    
    printf("ERROR: duplicated data input.\n");
    for(uint i=0; i<vDuplicated_type_cnt.size(); ++i){
        uint idx = std::get<0>( vDuplicated_type_cnt[i] ); // key as an index
        uint cnt = std::get<1>( vDuplicated_type_cnt[i] );
        printf("  %s inputted %d times from the user input.\n", vData[idx].data.c_str(), cnt);
    }
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Application
One of the application of this template function is `sstd::argparse()`. See [sstd::argparse()](../argparse.md) for more detail.

このテンプレート関数の応用の 1 つに `sstd::argparse()` があります．詳細は [sstd::argparse()](../argparse.md) をご確認ください．

## Implementation
- Header: [sstd/src/utils/vector/duplicated.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/utils/vector/duplicated.hpp)
- Test: [test/src_test/utils/vector/duplicated.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/utils/vector/duplicated.cpp)