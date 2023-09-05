# YAML
## Abstract
The SSTD YAML parser. `sstd::yaml_` seriese functions are the SSTD YAML parser set and are be used along with the `sstd::terp` class.
A instance of the `sstd::terp` class operates like a in**<u>terp</u>**reter object.
And the user can treat YAML file through the `sstd::terp` object.

SSTD YAML パーサ．`sstd::yaml_` 系の関数は SSTD の yaml パーサーセットであり，`sstd::terp` クラスとともに使用されます．
`sstd::terp` クラスのインスタンスは，インタープリタ (in**<u>terp</u>**reter) のオブジェクトのように動作します．
ユーザは `sstd::terp` オブジェクトを通して，YAML ファイルを扱うことができます．

## Header file
```cpp
namespace sstd{
    bool yaml_load     (           sstd::terp::var & ret_yml,  const        char* s);
    bool yaml_load     (           sstd::terp::var & ret_yml,  const std::string& s);
    bool yaml_load_all(std::vector<sstd::terp::var>& ret_vYml, const        char* s);
    bool yaml_load_all(std::vector<sstd::terp::var>& ret_vYml, const std::string& s);
    
    bool yaml_load    (            sstd::terp::var & ret_yml,  sstd::file& fp);
    bool yaml_load_all(std::vector<sstd::terp::var>& ret_vYml, sstd::file& fp);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| function01()  | en-xxxxxxx<br>ja-xxxxxxx |
| function02()  | en-xxxxxxx<br>ja-xxxxxxx |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = "Hello template!";
    sstd::printn(s);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix

## Implementation
- Source: [sstd/src/XXXXXX.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/XXXXXX.cpp)
- Header: [sstd/src/XXXXXX.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/XXXXXX.hpp)
- Test: [test/XXXXXX.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/XXXXXX.hpp)
  (Not implemented yet)

