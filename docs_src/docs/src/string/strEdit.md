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
    
    bool strcmp(const char*        str1, const char*        str2);
    bool strcmp(const char*        str1, const std::string& str2);
    bool strcmp(const std::string& str1, const char*        str2);
    bool strcmp(const std::string& str1, const std::string& str2);
}
```

## Functions
- Removing spaces and tabs.  
  空白 (半角スペース) とタブ文字の除去．

| Name | Description |
| --- | --- |
| lstrip    | Removing head spaces and tabs.<br/>文字列の先頭にある半角スペースとタブ文字を除去します． |
| lstrip_ow | Removing head spaces and tabs. `_ow` means overwrite.<br/>文字列の先頭にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| rstrip    | Removing tail spaces and tabs.<br/>文字列の末尾にある半角スペースとタブ文字を除去します． |
| rstrip_ow | Removing tail spaces and tabs. `_ow` means overwrite.<br/>文字列の末尾にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| strip     | Removing head and tail spaces and tabs.<br/>文字列の先頭と末尾にある半角スペースとタブ文字を除去します． |
| strip_ow  | Removing head and tail spaces and tabs. `_ow` means overwrite.<br/>文字列の先頭と末尾にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |

- String comparison  
  文字列の比較．引数の型の違いにより複数定義されている．

| Name | Description |
| --- | --- |
| strcmp | Comparing two strings given as input arguments and returns true if they are equal, false otherwise.<br/>入力引数に与えられる 2 つの文字列を比較し，等しい場合は true を，それ以外は false を返す． |

## Usage
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

## Implementation
- Source: [sstd/src/vector/strEdit.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strEdit.cpp)
- Header: [sstd/src/vector/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strEdit.hpp)
- Test: [test/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/strEdit.hpp)

