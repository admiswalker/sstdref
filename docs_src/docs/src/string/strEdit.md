# strEdit
## Abstract
`strEdit.hpp` / `strEdit.cpp` は，文字列を編集するための関数を収録している．

## Header file
```cpp
namespace sstd{
    std::vector<std::string> splitByLine(const std::string& str);
    
    std::vector<std::string> split(const char*        str, const char X);
    std::vector<std::string> split(const std::string& str, const char X);
    
    // remove space or tab.
    std::string              lstrip   (const        char* str); // removing head spaces
    std::string              lstrip   (const std::string& str); // removing head spaces
    void                     lstrip_ow(      std::string& str); // removing head spaces. ow: overwrite
    std::string              rstrip   (const        char* str); // removing tail spaces
    std::string              rstrip   (const std::string& str); // removing tail spaces
    void                     rstrip_ow(      std::string& str); // removing tail spaces. ow: overwrite
    std::string               strip   (const        char* str); // removing head and tail tab and spaces
    std::string               strip   (const std::string& str); // removing head and tail tab and spaces
    void                      strip_ow(      std::string& str); // removing head and tail tab and spaces. ow: overwrite
    std::vector<std::string>  strip   (const std::vector<std::string>& vec); // -> strip(str) // removing head and tail spaces
    
    std::string               stripAll   (const        char* str, const        char* stripList);
    std::string               stripAll   (const std::string& str, const        char* stripList);
    std::string               stripAll   (const        char* str, const std::string& stripList);
    std::string               stripAll   (const std::string& str, const std::string& stripList);

    void                      stripAll_ow(      std::string& str, const        char* stripList);
    void                      stripAll_ow(      std::string& str, const std::string& stripList);
}
```

## Description
### split string / 文字列の分割
| Function name | Description |
| --- | --- |
| splitByLine() | split the string with a line feed code.<br/>文字列を改行コードごとに分割します． |
| split() | split the string by a charactor of arg 2.<br/>第 2 引数の文字で文字列を分割します． |

### Remove spaces and tabs / 空白 (半角スペース) とタブ文字の除去

| Function name | Description |
| --- | --- |
| lstrip()    | remove head spaces and tabs.<br/>文字列の先頭にある半角スペースとタブ文字を除去します． |
| lstrip_ow() | remove head spaces and tabs. `_ow` means overwrite.<br/>文字列の先頭にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| rstrip()    | remove tail spaces and tabs.<br/>文字列の末尾にある半角スペースとタブ文字を除去します． |
| rstrip_ow() | remove tail spaces and tabs. `_ow` means overwrite.<br/>文字列の末尾にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| strip()     | remove head and tail spaces and tabs.<br/>文字列の先頭と末尾にある半角スペースとタブ文字を除去します． |
| strip_ow()  | remove head and tail spaces and tabs. `_ow` means overwrite.<br/>文字列の先頭と末尾にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| stripAll()    | remove all types of charactors in arg 2.<br/>第 2 引数にある全ての種類の文字を除去します． |
| stripAll_ow() | remove all types of charactors in arg 2. `_ow` means overwrite.<br/>第 2 引数にある全ての種類の文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |

## Usage
### splitByLine()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = "abc\ndef\n";
    std::vector<std::string> vS1 = sstd::splitByLine(s1);
    sstd::printn(vS1);
    
    std::string s2 = "\nabc\ndef\n\n";
    std::vector<std::string> vS2 = sstd::splitByLine(s2);
    sstd::printn(vS2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### split()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = "abc|def|";
    std::vector<std::string> vS1 = sstd::split(s1, '|');
    sstd::printn(vS1);
    
    std::string s2 = "|abc|def||";
    std::vector<std::string> vS2 = sstd::split(s2, '|');
    sstd::printn(vS2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### lstrip(), rstrip(), strip()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = "   abc   ";
    
    sstd::printn(sstd::lstrip(s));
    sstd::printn(sstd::rstrip(s));
    sstd::printn(sstd::strip(s));
    sstd::strip_ow(s); sstd::printn(s);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### stripAll()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = "   a x b x c   ";
    
    sstd::stripAll_ow(s, " x");
    sstd::printn(s);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/vector/strEdit.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strEdit.cpp)
- Header: [sstd/src/vector/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strEdit.hpp)
- Test: [test/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/strEdit.hpp)

