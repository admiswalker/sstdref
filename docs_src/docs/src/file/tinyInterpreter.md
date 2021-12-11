# tinyInterpreter
## Abstract
`getCommandList()` read text file, defineing middle of `/*~*/` and before `//` as a commnet.
And up to `;` is considered as one command list. The returning the value is formed as a list of command.

`getCommandList()` は txt ファイルを読み込みます．この際に，`/*~*/` で囲まれた区間や，同一行中で `//` より後ろの文字列をコメントとみなし取り除きます．
また，`;` までを一つのコマンドリストみなします．戻り値はコマンドのリストの形式となります．

## Header file
```cpp
namespace sstd{
    std::vector<std::string> getCommandList(const char* pReadFile);
    std::vector<std::string> splitByComma(const std::string& str);
}
```

## Usage
- <u>**tinyInterpreter.txt**</u>
```
#mdEx: cpp example (in:attachment:tinyInterpreter.txt)
// - In this file, middle of "/*~*/" and before "//" mean commnets.
//   And a ";" means the end of command.

// comment

/* comment */

/* 
comment 
comment 
comment 
*/


cmd01, cmd02,      , cmd04; // comment
cmd05, cmd06, cmd07;        // comment
cmd09, cmd10, cmd11, cmd12;
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    // reading "tinyInterpreter.txt" to vv_ret
    std::vector<std::string> v_line = sstd::getCommandList(R"(./tinyInterpreter.txt)");
    
    sstd::vvec<std::string> vv_ret(v_line.size());
    for(uint i=0; i<v_line.size(); ++i){
        std::vector<std::string> v_cmd = sstd::splitByComma(v_line[i]);
        for(uint n=0; n<v_cmd.size(); ++n){
            vv_ret[i] <<= v_cmd[n];
        }
    }
    sstd::printn(vv_ret);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/tinyInterpreter.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/tinyInterpreter.cpp)
- Header: [sstd/src/file/tinyInterpreter.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/tinyInterpreter.hpp)
- Test: [test/file/tinyInterpreter.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/tinyInterpreter.hpp)

