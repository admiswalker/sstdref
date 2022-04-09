# strmatch
## Abstract
`strmatch.hpp` contains string comparision functions.  
`strmatch.hpp` は文字列比較関数を収録しています．

## Header file
```cpp
namespace sstd{
    bool strcmp(const        char* str1, const        char* str2);
    bool strcmp(const        char* str1, const std::string& str2);
    bool strcmp(const std::string& str1, const        char* str2);
    bool strcmp(const std::string& str1, const std::string& str2);
    
    bool strmatch(const        char* str, const        char* wildcard);
    bool strmatch(const        char* str, const std::string& wildcard);
    bool strmatch(const std::string& str, const        char* wildcard);
    bool strmatch(const std::string& str, const std::string& wildcard);
    
    bool strmatch_getWC(const        char* str, const        char* wildcard, std::string& retWC);
    bool strmatch_getWC(const        char* str, const std::string& wildcard, std::string& retWC);
    bool strmatch_getWC(const std::string& str, const        char* wildcard, std::string& retWC);
    bool strmatch_getWC(const std::string& str, const std::string& wildcard, std::string& retWC);
    
    bool pathmatch(const        char* str, const        char* wildcard);
    bool pathmatch(const        char* str, const std::string& wildcard);
    bool pathmatch(const std::string& str, const        char* wildcard);
    bool pathmatch(const std::string& str, const std::string& wildcard);
    
    bool isNum           (const char rhs);
    bool isNum           (const char* rhs);
    bool isNum           (const std::string& rhs);
    
    bool isAlphabet      (const char rhs);
    bool isAlphabet      (const char* rhs);
    bool isAlphabet      (const std::string& rhs);
    
    bool isAlphabet_upper(const char rhs);
    bool isAlphabet_upper(const char* rhs);
    bool isAlphabet_upper(const std::string& rhs);
    
    bool isAlphabet_lower(const char rhs);
    bool isAlphabet_lower(const char* rhs);
    bool isAlphabet_lower(const std::string& rhs);
    
    bool charIn(const char lhs, const        char* rhs); // Is lhs in rhs ?
    bool charIn(const char lhs, const std::string& rhs); // Is lhs in rhs ?
    
    bool charIn(const        char* lhs, const        char* rhs); // Is lhs in rhs ?
    bool charIn(const        char* lhs, const std::string& rhs); // Is lhs in rhs ?
    bool charIn(const std::string& lhs, const        char* rhs); // Is lhs in rhs ?
    bool charIn(const std::string& lhs, const std::string& rhs); // Is lhs in rhs ?
    
    bool charIn_all(const        char* lhs, const        char* rhs); // Is all lhs char(s) in rhs ?
    bool charIn_all(const        char* lhs, const std::string& rhs); // Is all lhs char(s) in rhs ?
    bool charIn_all(const std::string& lhs, const        char* rhs); // Is all lhs char(s) in rhs ?
    bool charIn_all(const std::string& lhs, const std::string& rhs); // Is all lhs char(s) in rhs ?
    
    bool strIn(const char*        lhs, const char*        rhs); // is lhs in rhs ? (is rhs include lhs ?)
    bool strIn(const char*        lhs, const std::string& rhs);
    bool strIn(const std::string& lhs, const char*        rhs);
    bool strIn(const std::string& lhs, const std::string& rhs);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| strcmp()      | A function that compares whether two input strings exactly the same or not. When two arguments of strings are exactly the same, true is returned. Otherwise false is returned.<br/>2 つの入力引数が完全に一致するかどうか判定する関数．2 つの入力引数が完全に一致する場合は，true を，それ以外は false を返します． |
| strmatch()    | A function that judges whether a string and a string using wildcard are considered equivalent or not. When a string of 1st argument and a string of the 2nd argument can use wildcard considered equivalent, true is returned. Otherwise false is returned. Charactors of `*` or `?` can use as wildcards.<br/>文字列とワイルドカード付き文字列が等価と見なせるか判定する関数．第一引数の文字列と，ワイルドカードを使える第二引数の文字列が等価と見なせる場合は，true を，それ以外は false を返します．また，wildcard には，`*` と `?` を使うことができます． |
| strmatch_getWC() | A function to get a substring indicated by a wildcard. The 3rd argument will return the substring of the 1st argument that matches for the wildcard (`*` or `?`) of the 2nd argument. The other handlings work the same as `strmatch()`.<br/>ワイルドカードが示す部分文字列を取得する関数．第三引数は，第一引数の文字列の内，第二引数の wildcard (`*` または `?`) と一致する部分を返却します．それ以外は，`strmatch()` と同様に動作します． |
| pathmatch()   | A function that judges whether a path string and a path string using wildcard are considered equivalent or not. The splitter string (`/` or `\\`) cannot be excluded with wildcards. The other handlings work the same as `strmatch()`.<br/>パスの比較用関数．スプリッタとなる文字列 (`/` または `\\`) が wildcard による除外を受付ません．それ以外は，`strmatch()` と同様に動作します． |
| isNum()       | A function that judges whether a whole string is configured by numerical string or not. When all the character or string of the 1st argument is in the range of `0` to `9` as a ASCII Code, true is returned. Otherwise false is returned.<br/>全ての文字列が数値で構成されているか判定する関数．第一引数に渡される全ての文字または文字列が ASCII Code での `0` ~ `9` の範囲にある場合は，true を，それ以外は false を返します． |
| isAlphabet()  | A function that judges whether a whole string is configured by alphabet or not. When a character or whole string of the 1st argument are in the range of `A` to `Z` or `a` to `z` as a ASCII Code, true is returned. Otherwise false is returned.<br/>全ての文字列がアルファベットで構成されているか判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `A` ~ `Z` または `a` ~ `z` の範囲にある場合は，true を，それ以外は false を返します． |
| isAlphabet_upper() | A function that judges whether a whole string is configured by uppercase or not. When all the character or string of the 1st argument is in the range of `A` to `Z` as a ASCII Code, true is returned. Otherwise false is returned.<br/>全ての文字列が大文字のアルファベットで構成されているか判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `A` ~ `Z` の範囲にある場合は，true を，それ以外は false を返します． |
| isAlphabet_lower() | A function that judges whether a whole string is configured by lowercase or not. When all the character or string of the 1st argument is in the range of `a` to `z` as a ASCII Code, true is returned. Otherwise false is returned.<br/>全ての文字列が小文字のアルファベットで構成されているか判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `a` ~ `z` の範囲にある場合は，true を，それ以外は false を返します． |
| charIn()      | A function that judges whether a particular character is included in a string or not. When the character of the 1st argument is included in the string of the 2nd argument, true is returned. Otherwise false is returned.<br>特定の文字を内包するか判定する関数．第一引数の文字が，第二引数の文字列に含まれる場合は，true を，それ以外は false を返します． |
| charIn_all()  | A function that judges whether all of particular character is included in a string or not. When the character of the 1st argument is included in the string of the 2nd argument, true is returned. Otherwise false is returned.<br>特定の文字を全て内包するか判定する関数．第一引数の文字が，第二引数の文字列に含まれる場合は，true を，それ以外は false を返します． |
| strIn()       | A function that judges whether a particular string is included in a string or not. When the string of the 1st argument is included in the string of the 2nd argument, true is returned. Otherwise false is returned.<br>特定の文字列を内包するか判定する関数．第一引数の文字列が，第二引数の文字列に含まれる場合は，true を，それ以外は false を返します． |

## Usage
### strcmp()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::strcmp("abc def", "abc def") );
    sstd::printn( sstd::strcmp("abc def", "abc  ef") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### strmatch(), strmatch_getWC()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = "TOKYOTO...";
    sstd::printn( sstd::strmatch(s, "??KYOTO*") );

    std::string ret;
    sstd::printn( sstd::strmatch_getWC(s, "TO*...", ret) );
    sstd::printn(ret);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### pathmatch()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::string s = "/a/b/c/example.txt";
    sstd::printn( sstd::pathmatch(s, "/*/*/*/*.txt") );
    sstd::printn( sstd::pathmatch(s, "/*/*/*.txt") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### isNum()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isNum('0') );
    sstd::printn( sstd::isNum('A') );
    sstd::printn( sstd::isNum('a') ); printf("\n");
    
    sstd::printn( sstd::isNum("0123456789") );
    sstd::printn( sstd::isNum("012345678a") );
    sstd::printn( sstd::isNum("abcdeABCDE") ); printf("\n");
    
    sstd::printn( sstd::isNum(std::string("0123456789")) );
    sstd::printn( sstd::isNum(std::string("012345678a")) );
    sstd::printn( sstd::isNum(std::string("abcdeABCDE")) ); printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### isAlphabet()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isAlphabet('0') );
    sstd::printn( sstd::isAlphabet('A') );
    sstd::printn( sstd::isAlphabet('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet("0123456789") );
    sstd::printn( sstd::isAlphabet("ABCDEFTGI9") );
    sstd::printn( sstd::isAlphabet("abcdeABCDE") ); printf("\n");
    
    sstd::printn( sstd::isAlphabet(std::string("0123456789")) );
    sstd::printn( sstd::isAlphabet(std::string("ABCDEFTGI9")) );
    sstd::printn( sstd::isAlphabet(std::string("abcdeABCDE")) ); printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### isAlphabet_upper()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isAlphabet_upper('0') );
    sstd::printn( sstd::isAlphabet_upper('A') );
    sstd::printn( sstd::isAlphabet_upper('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_upper("0123456789") );
    sstd::printn( sstd::isAlphabet_upper("ABCDEFGHIJ") );
    sstd::printn( sstd::isAlphabet_upper("abcdeABCDE") ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_upper(std::string("0123456789")) );
    sstd::printn( sstd::isAlphabet_upper(std::string("ABCDEFGHIJ")) );
    sstd::printn( sstd::isAlphabet_upper(std::string("abcdeABCDE")) ); printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### isAlphabet_lower()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isAlphabet_lower('0') );
    sstd::printn( sstd::isAlphabet_lower('A') );
    sstd::printn( sstd::isAlphabet_lower('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_lower("0123456789") );
    sstd::printn( sstd::isAlphabet_lower("abcdeABCDE") );
    sstd::printn( sstd::isAlphabet_lower("abcdefghij") ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_lower(std::string("0123456789")) );
    sstd::printn( sstd::isAlphabet_lower(std::string("abcdeABCDE")) );
    sstd::printn( sstd::isAlphabet_lower(std::string("abcdefghij")) ); printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### charIn()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::charIn('c', "abcdef") ); // 'c' exists in "abcdef".
    sstd::printn( sstd::charIn("abc", "abcdef") ); // 'a', 'b' or 'c' exist in "abcdef".
    sstd::printn( sstd::charIn_all("abx", "abcdef") ); // 'x' dose not exist in "abcdef".
    sstd::printn( sstd::charIn_all("cba", "abcdef") ); // 'a', 'b' and 'c' exist in "abcdef".
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### strIn()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::strIn("def", "abcdefgh") );
    sstd::printn( sstd::strIn("defx", "abcdefgh") );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/string/strmatch.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/string/strmatch.cpp)
- Header: [sstd/src/string/strmatch.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/string/strmatch.hpp)
- Test: [test/string/strmatch.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/string/strmatch.hpp)
