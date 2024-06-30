# strEdit
## Abstract
`strEdit.hpp` / `strEdit.cpp` は，文字列を編集するための関数を収録している．

## Header file
```cpp
namespace sstd{
    bool extract_quoted  (std::vector<std::string>& ret, const        char* str);
    bool extract_quoted  (std::vector<std::string>& ret, const std::string& str);
    bool extract_unquoted(            std::string & ret, const        char* str);
    bool extract_unquoted(            std::string & ret, const std::string& str);
    
    //---
    
    std::vector<std::string> splitByLine(const        char* str);
    std::vector<std::string> splitByLine(const std::string& str);
    
    bool splitByLine_quotes(std::vector<std::string>& ret, const        char* str);
    bool splitByLine_quotes(std::vector<std::string>& ret, const std::string& str);
    
    std::vector<std::string> split(const char*        str);
    std::vector<std::string> split(const std::string& str);
    std::vector<std::string> split(const char*        str, const char X);
    std::vector<std::string> split(const std::string& str, const char X);
    std::vector<std::string> split(const char*        str, const char*        X);
    std::vector<std::string> split(const std::string& str, const std::string& X);
    
    std::vector<std::string> split_rmSpace(const char*        str);               // rm: remove
    std::vector<std::string> split_rmSpace(const std::string& str);               // rm: remove
    std::vector<std::string> split_rmSpace(const char*        str, const char X); // rm: remove
    std::vector<std::string> split_rmSpace(const std::string& str, const char X); // rm: remove
    
    bool split_quotes(std::vector<std::string>& ret, const        char* str);
    bool split_quotes(std::vector<std::string>& ret, const std::string& str);
    bool split_quotes(std::vector<std::string>& ret, const        char* str, const char X);
    bool split_quotes(std::vector<std::string>& ret, const std::string& str, const char X);
    bool split_quotes(std::vector<std::string>& ret, const        char* str, const char*        X);
    bool split_quotes(std::vector<std::string>& ret, const std::string& str, const std::string& X);

    //---
    
    // remove space or tab.
    std::string              lstrip   (const                    char * str); // removing head tab and spaces
    std::string              lstrip   (const             std::string & str); // removing head tab and spaces
    std::vector<std::string> lstrip   (const std::vector<std::string>& vec); // removing tail tab and spaces
    void                     lstrip_ow(                  std::string & str); // removing head tab and spaces. ow: overwrite
    void                     lstrip_ow(      std::vector<std::string>& vec); // removing tail tab and spaces. ow: overwrite
    std::string              rstrip   (const                    char * str); // removing tail tab and spaces
    std::string              rstrip   (const             std::string & str); // removing tail tab and spaces
    std::vector<std::string> rstrip   (const std::vector<std::string>& vec); // removing tail tab and spaces
    void                     rstrip_ow(                  std::string & str); // removing tail tab and spaces. ow: overwrite
    void                     rstrip_ow(      std::vector<std::string>& vec); // removing tail tab and spaces. ow: overwrite
    std::string               strip   (const                    char * str); // removing head and tail tab and spaces
    std::string               strip   (const             std::string & str); // removing head and tail tab and spaces
    std::vector<std::string>  strip   (const std::vector<std::string>& vec); // -> strip(str) // removing head and tail spaces
    void                      strip_ow(                  std::string & str); // removing head and tail tab and spaces. ow: overwrite
    void                      strip_ow(      std::vector<std::string>& vec); // -> strip(str) // removing head and tail spaces
    
    std::string              lstrip   (const        char* str, const char c);
    std::string              lstrip   (const std::string& str, const char c);
    void                     lstrip_ow(      std::string& str, const char c);
    std::string              rstrip   (const        char* str, const char c);
    std::string              rstrip   (const std::string& str, const char c);
    void                     rstrip_ow(      std::string& str, const char c);
    std::string               strip   (const        char* str, const char c);
    std::string               strip   (const std::string& str, const char c);
    void                      strip_ow(      std::string& str, const char c);
    
    std::string               stripAll   (const        char* str, const        char  c        );
    std::string               stripAll   (const std::string& str, const        char  c        );
    void                      stripAll_ow(      std::string& str, const        char  c        );
    
    std::string               stripAll   (const        char* str, const        char* stripList);
    std::string               stripAll   (const std::string& str, const        char* stripList);
    std::string               stripAll   (const        char* str, const std::string& stripList);
    std::string               stripAll   (const std::string& str, const std::string& stripList);

    void                     lstripAll_ow(      std::string& str, const        char* stripList);
    void                     lstripAll_ow(      std::string& str, const std::string& stripList);
    void                     rstripAll_ow(      std::string& str, const        char* stripList);
    void                     rstripAll_ow(      std::string& str, const std::string& stripList);
    void                      stripAll_ow(      std::string& str, const        char* stripList);
    void                      stripAll_ow(      std::string& str, const std::string& stripList);
    // todo: rm '\t'
    // todo: implementing memcopy version. Ref: https://postd.cc/how-quickly-can-you-remove-spaces-from-a-string/
    
    std::string strip_quotes(                            const        char* str);
    std::string strip_quotes(                            const std::string& str);
    std::string strip_quotes(bool& ret_sq, bool& ret_dq, const        char* str); // _sq: single quatation, _dq: double quotation
    std::string strip_quotes(bool& ret_sq, bool& ret_dq, const std::string& str); // _sq: single quatation, _dq: double quotation
    
    //---
    
    std::string join(const std::vector<std::string>& v, const        char  delimiter);
    std::string join(const std::vector<std::string>& v, const        char* delimiter);
    std::string join(const std::vector<std::string>& v, const std::string& delimiter);
}
```

## Description
### extract string / 文字列の抽出
| Function name | Description |
| --- | --- |
| extract_quoted()   | extracts the quoted string. As a quoted type, double quotes or single quotes are required. When a quotation is not closed, this function returns false.<br/>Quotation で囲われた文字列を抽出します．Quotation には Double quotation または singhle quotation を指定します．Quotation が閉じていない場合は false を返します．|
| extract_unquoted() | extracts the unquoted string. As a quoted type, double quotes or single quotes are required. When a quotation is not closed, this function returns false.<br/>Quotation で囲われていない文字列を抽出します．Quotation には Double quotation または singhle quotation を指定します．Quotation が閉じていない場合は false を返します．|

### split string / 文字列の分割
| Function name | Description |
| --- | --- |
| splitByLine() | splits the string with a line feed code.<br/>文字列を改行コードごとに分割します． |
| splitByLine_quotes() | splits the string with a line feed code ignoring the line feed code between quotes. As a quoted type, double quotes or single quotes are required. When a quatation is not closed, this function returns false.<br/>Quotation で囲われた改行コードを無視する形で，文字列を改行コードごとに分割します． Quotation には Double quotation または singhle quotation を指定します．Quotation が閉じていない場合は false を返します． |
| split() | splits the string by a character of arg 2.<br/>第 2 引数の文字で文字列を分割します． |
| split_rmSpace(str) | splits the string by a space (' ') and removes the spaces on the head and tail of string.<br/>空白文字 (' ') で文字列を分割して，前後の空白文字も削除します． |
| split_rmSpace(str, X) | splits the string by a character of arg 2 and removes the spaces.<br/>第 2 引数の文字で文字列を分割し，前後の空白文字を削除します． |
| split_quotes() | splits the string by a character of arg 2 ignoring the line feed code between quotes. As a quoted type, double quotes or single quotes are required. When a quatation is not closed, this function returns false.<br/>Quotation で囲われた改行コードを無視する形で，第 2 引数の文字で文字列を分割します．Quotation には Double quotation または singhle quotation を指定します．Quotation が閉じていない場合は false を返します． |

### Remove spaces and tabs / 空白 (半角スペース) とタブ文字の除去
| Function name | Description |
| --- | --- |
| lstrip()       | removes head spaces and tabs.<br/>文字列の先頭にある半角スペースとタブ文字を除去します． |
| lstrip_ow()    | removes head spaces and tabs. `_ow` means overwrite.<br/>文字列の先頭にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| rstrip()       | removes tail spaces and tabs.<br/>文字列の末尾にある半角スペースとタブ文字を除去します． |
| rstrip_ow()    | removes tail spaces and tabs. `_ow` means overwrite.<br/>文字列の末尾にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
|  strip()       | removes head and tail spaces and tabs.<br/>文字列の先頭と末尾にある半角スペースとタブ文字を除去します． |
|  strip_ow()    | removes head and tail spaces and tabs. `_ow` means overwrite.<br/>文字列の先頭と末尾にある半角スペースとタブ文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
|  stripAll()    | removes all types of characters in arg 2.<br/>第 2 引数にある全ての種類の文字を除去します． |
| lstripAll_ow() | removes all types of characters in arg 2 from the left (head) of the string until all the types of characters in arg 2 is included. If a character not contained in the 2nd arg's characters occurs, removal process is stopped. `_ow` means overwrite.<br/>第 2 引数に含まれる文字種類が現れる間，第 2 引数の文字を先頭から除去します．第 2 引数に含まれない文字が現れた場合，削除プロセスは停止します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| rstripAll_ow() | removes all types of characters in arg 2 from the right (tail) of the string until all the types of characters in arg 2 is included. If a character not contained in the 2nd arg's characters occurs, removal process is stopped. `_ow` means overwrite.<br/>第 2 引数に含まれる文字種類が現れる間，第 2 引数の文字を末尾から除去します．第 2 引数に含まれない文字が現れた場合，削除プロセスは停止します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
|  stripAll_ow() | removes all types of characters in arg 2. `_ow` means overwrite.<br/>第 2 引数にある全ての種類の文字を除去します．`_ow` は overwrite の意味で，引数に結果を上書きします． |
| strip_quotes() | removes head and tail quotes after removing head and tail spaces and tabs.<br/>文字列の先頭にある半角スペースとタブ文字を除去した後，Quotation を取り除きます． |

### Join objects / オブジェクトの結合
| Function name | Description |
| --- | --- |
| join() | joins the `std::vector<std::string>` of arg 1, inserting delimiter of arg 2.<br/>オブジェクトの間に delimiter を挿入しながら，第 1 引数の `std::vector<std::string>` を結合します． |


## Usage
### extract string / 文字列の抽出
#### extract_quoted() / extract_unquoted() 
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = R"( abc " def " ghi ' jkl ' )";
    
    std::vector<std::string> ret_vs_q;
    bool ret_tf_q = sstd::extract_quoted(ret_vs_q, s);
    
    sstd::printn(ret_tf_q);
    sstd::printn(ret_vs_q);
    
    std::string ret_s_uq;
    bool ret_tf_uq = sstd::extract_unquoted(ret_s_uq, s);
    
    sstd::printn(ret_tf_uq);
    sstd::printn(ret_s_uq );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### split string / 文字列の分割
#### splitByLine()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = "abc\ndef\n";
    std::vector<std::string> vS1 = sstd::splitByLine(s1);
    sstd::printn(vS1);
    
    std::string s2 = "abc\r\ndef\r\n";
    std::vector<std::string> vS2 = sstd::splitByLine(s2);
    sstd::printn(vS2);
    
    std::string s3 = "\nabc\ndef\n\n";
    std::vector<std::string> vS3 = sstd::splitByLine(s3);
    sstd::printn(vS3);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### splitByLine_quotes()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = "abc\n\"def\nghi\"jkl";
    std::vector<std::string> ret_vs1;
    bool ret_tf1 = sstd::splitByLine_quotes(ret_vs1, s1);
    sstd::printn(ret_tf1);
    sstd::printn(ret_vs1);
    printf("\n");
    
    std::string s2 = "abc\n'def\nghi'jkl";
    std::vector<std::string> ret_vs2;
    bool ret_tf2 = sstd::splitByLine_quotes(ret_vs2, s2);
    sstd::printn(ret_tf2);
    sstd::printn(ret_vs2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### split()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = "a b   c";
    std::vector<std::string> vS1 = sstd::split(s1);
    sstd::printn(vS1);
    
    std::string s2 = "a | b | c ";
    std::vector<std::string> vS2 = sstd::split(s2, '|');
    sstd::printn(vS2);
    
    std::string s3 = "a | b | c |";
    std::vector<std::string> vS3 = sstd::split(s3, '|');
    sstd::printn(vS3);
    
    std::string s4 = "a | b || c |";
    std::vector<std::string> vS4 = sstd::split(s4, "||");
    sstd::printn(vS4);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### split_rmSpace()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = " abc  def  ghi  ";
    std::vector<std::string> vS1 = sstd::split_rmSpace(s1);
    sstd::printn(vS1);
    
    std::string s2 = " abc | def ||  ghi  ";
    std::vector<std::string> vS2 = sstd::split_rmSpace(s2, '|');
    sstd::printn(vS2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### split_quotes()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s1 = "abc|\"def|ghi\"jkl";
    std::vector<std::string> ret_vs1;
    bool ret_tf1 = sstd::split_quotes(ret_vs1, s1, '|');
    sstd::printn(ret_tf1);
    sstd::printn(ret_vs1);
    
    std::string s2 = "abc|'def|ghi'jkl";
    std::vector<std::string> ret_vs2;
    bool ret_tf2 = sstd::split_quotes(ret_vs2, s2, '|');
    sstd::printn(ret_tf2);
    sstd::printn(ret_vs2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Remove spaces and tabs / 空白 (半角スペース) とタブ文字の除去
#### lstrip()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn(sstd::lstrip("   a b c   "));
    sstd::printn(sstd::lstrip("---a-b-c---", '-'));

    std::string s1 = "   a b c   ";
    sstd::lstrip_ow(s1);
    sstd::printn(s1);
    
    std::string s2 = "---a-b-c---";
    sstd::lstrip_ow(s2, '-');
    sstd::printn(s2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### rstrip()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn(sstd::rstrip("   a b c   "));
    sstd::printn(sstd::rstrip("---a-b-c---", '-'));

    std::string s1 = "   a b c   ";
    sstd::rstrip_ow(s1);
    sstd::printn(s1);
    
    std::string s2 = "---a-b-c---";
    sstd::rstrip_ow(s2, '-');
    sstd::printn(s2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### strip()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn(sstd::strip("   a b c   "));
    sstd::printn(sstd::strip("---a-b-c---", '-'));

    std::string s1 = "   a b c   ";
    sstd::strip_ow(s1);
    sstd::printn(s1);
    
    std::string s2 = "---a-b-c---";
    sstd::strip_ow(s2, '-');
    sstd::printn(s2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### stripAll(), lstripAll(), rstripAll()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s;
    
    s = "   a x b x c   ";
    sstd::stripAll_ow(s, " x");
    sstd::printn(s);
    
    s = "   a x b x c   ";
    sstd::lstripAll_ow(s, " ax");
    sstd::printn(s);
    
    s = "   a x b x c   ";
    sstd::rstripAll_ow(s, " cx");
    sstd::printn(s);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### strip_quotes()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn(sstd::strip_quotes("   \"a x b x c\"   "));
    sstd::printn(sstd::strip_quotes("   'a x b x c'   "));
    printf("\n");
    
    bool ret_sq1=false, ret_dq1=false;
    sstd::printn(sstd::strip_quotes(ret_sq1, ret_dq1, "   \"a x b x c\"   "));
    sstd::printn(ret_sq1);
    sstd::printn(ret_dq1);
    printf("\n");
    
    bool ret_sq2=false, ret_dq2=false;
    sstd::printn(sstd::strip_quotes(ret_sq2, ret_dq2, "   'a x b x c'   "));
    sstd::printn(ret_sq2);
    sstd::printn(ret_dq2);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### join()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> v = {"a", "b", "c"};
    sstd::printn(sstd::join(v, ','));
    sstd::printn(sstd::join(v, ", "));
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/string/strEdit.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/string/strEdit.cpp)
- Header: [sstd/src/string/strEdit.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/string/strEdit.hpp)
- Test: [test/src_test/string/strEdit.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/string/strEdit.cpp)

