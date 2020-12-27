# strEdit
## Abstract
```strEdit.hpp``` / ```strEdit.cpp``` は，文字列を編集するための関数を収録している．

## Header file
```c++
namespace sstd{
    std::vector<uint8>       readAll_bin(const char*        pReadFile); // read all of the file as a binary
    std::vector<uint8>       readAll_bin(const std::string&  readFile); // read all of the file as a binary
    
    bool                     writeAll_bin(const char*        pWritePath, std::vector<uint8>& rhs);
    bool                     writeAll_bin(const std::string&  writePath, std::vector<uint8>& rhs);
    
    std::string              readAll(const char*        pReadFile); // readAll_str()
    std::string              readAll(const std::string&  readFile); // readAll_str()
    std::string              readAll_withoutBOM(const char*        pReadFile);
    std::string              readAll_withoutBOM(const std::string&  readFile);
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
    
    bool strIn(const char*        lhs, const char*        rhs); // is lhs in rhs ? (is rhs include lhs ?)
    bool strIn(const char*        lhs, const std::string& rhs);
    bool strIn(const std::string& lhs, const char*        rhs);
    bool strIn(const std::string& lhs, const std::string& rhs);
}
```

## Functions
- 空白 (半角スペース) とタブ文字の除去．

| 名前 | 説明 |
| --------- | --- |
| lstrip    | 文字列の先頭にある半角スペースとタブ文字を除去します． |
| lstrip_ow | 文字列の先頭にある半角スペースとタブ文字を除去します．```_ow``` は overwrite の意味で，引数に結果を上書きします． |
| rstrip    | 文字列の末尾にある半角スペースとタブ文字を除去します． |
| rstrip_ow | 文字列の末尾にある半角スペースとタブ文字を除去します．```_ow``` は overwrite の意味で，引数に結果を上書きします． |
| strip     | 文字列の先頭と末尾にある半角スペースとタブ文字を除去します． |
| strip_ow  | 文字列の先頭と末尾にある半角スペースとタブ文字を除去します．```_ow``` は overwrite の意味で，引数に結果を上書きします． |

- 文字列の比較．引数の型の違いにより複数定義されている．

| 名前 | 説明 |
| --- | --- |
| strcmp | 入力引数に与えられる 2 つの文字列を比較し，等しい場合は true を，それ以外は false を返す． |

## Usage

## Others
- Implementation: [sstd/src/vector/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strEdit.hpp)
- Test code: [test/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/strEdit.hpp)

