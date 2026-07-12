# argstack
## Abstract
`argstack.hpp` contains the template functions for repackaging variable length arguments into `std::vector<T>(s)`.  
`argstack.hpp` は，可変長引数を `std::vector<T>` に積み直すためのテンプレート関数を収録している．

## Header file
```cpp
namespace sstd{
    template<typename T, class... Args>
    void argstack(std::vector<T>& res_stack, Args... args);

    template<class... ResArgs, class... Args>
    void argstack(const std::tuple<ResArgs...>& res_tuple_pV, Args... args);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| `argstack(vec<T>&, Args...)` | copies the provided variable length arguments after 2nd arg(s) into `std::vector<T>` specified as the 1st arg. <br>第 2 引数以降に入力された可変長引数を第 1 引数の `std::vector<T>` にコピーします． |
| `argstack(tpl<vec<T>*, ...>&, Args...)` | copies the provided variable length arguments after 2nd arg(s) into `std::tuple<std::vector<T>*, ...>` specified as the 1st arg with separating the variable by the type of `std::vector<T>*`. <br/>**Note**: The addresses of `std::vector<T>` are required to pass. <br>入力された可変長引数を型ごとに第 1 引数の `std::tuple<>` に格納された `std::vector<T>` のアドレスにコピーします．<br/>**注意**: `std::vector<T>` のアドレスを渡す必要があります． |

## Usage
### A single type of variable length arguments / 単一の可変長引数型
#### `argstack(vec<T>&, Args...)`
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<int> vi;
    sstd::argstack(vi, 1, 2, 3);
    sstd::printn(vi);
    
    std::vector<std::string> vs;
    sstd::argstack(vs, std::string("A"), std::string("B"), std::string("C"));
    sstd::printn(vs);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Multiple types of variable length arguments / 複数の可変長引数型
#### `argstack(tpl<vec<T>*, ...>&, Args...)`
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <string>
struct ExStruct{ // A user defined structure.
    std::string s="hello";
};
namespace sstd{
    std::string to_string(const struct ExStruct& rhs){ // for `sstd::printn()`
        return '"'+rhs.s+'"';
    }
}
#include <sstd/sstd.hpp> // include this header after the definition of `sstd::to_string(const ExStruct& rhs)` for `sstd::printn()`

int main(){
    std::vector<bool> vb;
    std::vector<int> vi;
    std::vector<std::string> vs;
    std::vector<double> vd;
    std::vector<struct ExStruct> ve;
    
    sstd::argstack(std::make_tuple(&vb, &vi, &vs, &vd, &ve), 1.0, 2.0, 3.0, 1, 2, ExStruct(), std::string("A"), 3, std::string("B"), ExStruct(), std::string("C"));
    sstd::printn(vb);
    sstd::printn(vi);
    sstd::printn(vs);
    sstd::printn(vd);
    sstd::printn(ve);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix

One of the application of this template function is `sstd::argparse()`. See [sstd::argparse()](./argparse.md) for more detail.

このテンプレート関数の応用の 1 つに `sstd::argparse()` があります．詳細は [sstd::argparse()](./argparse.md) をご確認ください．

## Implementation
- Header: [sstd/src/utils/argstack.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/utils/argstack.hpp)
- Test: [test/src_test/utils/argstack.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/utils/argstack.cpp)