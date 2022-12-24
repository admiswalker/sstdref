# pdbg
## Abstract
`pdbg` prints debug information.  
`pdbg` はデバッグ情報を出力します．

## Header file
```cpp
namespace sstd{
    inline void pdbg(...){}
    inline void pdbg_if(...){}
    inline void pdbg_if_exit(...){}
    inline void pdbg_if_stop_exit(...){}
    inline void dbg(...){}
    inline void ndbg(...){}
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| pdbg()        | A function to print debug messages with file name, function name and line number.<br>デバッグメッセージ出力用の関数．呼び出したファイルの名前，関数名，行数とエラーメッセージを出力する． |
| pdbg_if()     | <br> |
| pdbg_if_exit()       | <br> |
| pdbg_if_stop_exit()  | <br> |
| dbg()         | <br> |
| ndbg()        | <br> |

## Usage
### pdbg
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::pdbg("ERROR: printing error message.\n");
    printf("\n");
    
    std::string fileName = "NotExistingFile.txt";
    sstd::file fp;
    if(!fp.fopen(fileName, "rb")){ sstd::pdbg("ERROR: fopen is failed. \"%s\" is not exist!\n", fileName.c_str()); return -1; }
    
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
**NOTE1:**<br>
The above output path is complex because the compile path for this file is complex.<br>
上記で複雑なパスが出力されるのは，このファイルをコンパイルするパスが複雑なためです．<br>
**NOTE2:**<br>
`[31m` treat as red on the terminal.<br>
`[31m` は端末上で赤色として扱われます．


### pdbg_if
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    printf("True: "); sstd::pdbg_if(true, "ERROR: printing error message.\n");
    printf("False: "); sstd::pdbg_if(false, "ERROR: printing error message.\n"); printf("\n");
    
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
**NOTE1:**<br>
The above output path is complex because the compile path for this file is complex.<br>
上記で複雑なパスが出力されるのは，このファイルをコンパイルするパスが複雑なためです．<br>
**NOTE2:**<br>
`[31m` treat as red on the terminal.<br>
`[31m` は端末上で赤色として扱われます．


## Implementation
- Source: header only
- Header: [sstd/src/print/pdbg.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/print/pdbg.hpp)
- Test: [test/print/pdbg.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/print/pdbg.hpp)

