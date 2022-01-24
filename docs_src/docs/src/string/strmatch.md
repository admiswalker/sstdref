# strmatch
## Abstract
`strmatch.hpp` contains string comparision functions.  
`strmatch.hpp` は文字列比較関数を収録しています．

## Header file
```cpp
namespace sstd{
    bool strmatch(const        char* str, const        char* wildCard);
    bool strmatch(const        char* str, const std::string& wildCard);
    bool strmatch(const std::string& str, const        char* wildCard);
    bool strmatch(const std::string& str, const std::string& wildCard);
    
    bool strmatch_getWC(const        char* str, const        char* wildCard, std::string& retWC);
    bool strmatch_getWC(const        char* str, const std::string& wildCard, std::string& retWC);
    bool strmatch_getWC(const std::string& str, const        char* wildCard, std::string& retWC);
    bool strmatch_getWC(const std::string& str, const std::string& wildCard, std::string& retWC);
    
    bool pathmatch(const        char* str, const        char* wildCard);
    bool pathmatch(const        char* str, const std::string& wildCard);
    bool pathmatch(const std::string& str, const        char* wildCard);
    bool pathmatch(const std::string& str, const std::string& wildCard);
    
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
    
    bool strIn(const char*        lhs, const char*        rhs); // is lhs in rhs ? (is rhs include lhs ?)
    bool strIn(const char*        lhs, const std::string& rhs);
    bool strIn(const std::string& lhs, const char*        rhs);
    bool strIn(const std::string& lhs, const std::string& rhs);
}
```

## Description
| Function Name | Description |
| ------------- | ----------- |
| strmatch()    | A function to compare strings. The return value returns the match / mismatch of the strings passed to the 1st argument and the 2nd argument. And the string of the 2nd argument can contain wild card (`*` or `?`).<br/>文字列比較用の関数．戻り値は，第一引数と第二引数に渡された文字列の一致・不一致を返却します．また，第二引数の文字列には wild card (`*` または `?`) を含めることができます． |
| strmatch_getWC() | A function to get a substring. In the 3rd argument, the part of the 1st argument string that matches the wild card (`*` or `?`) of 2nd argument is returned. The other handling of the return value, the 1st argument, and the 2nd argument is the same as `strmatch ()`.<br/>部分文字列取得用の関数．第三引数が，第一引数の文字列のうち，第二引数の wild card (`*` または `?`) と一致する部分を返却します．戻り値と第一引数，第二引数の扱いは `strmatch()` と同じです． |
| pathmatch()   | A function to compare a paths of strings. The splitter string (`/` or `\\`) does not accept wild card exclusions. The other handlings work the same as `strmatch ()`.<br/>パスの比較用関数．スプリッタとなる文字列 (`/` または `\\`) が wild card による除外を受付ません．それ以外は，`strmatch()` と同様に動作します． |
| isNum()       | A function that judges if a string is configured by numerical string. Determine if a character or all of the string passed to the 1st argument are in the range of `0` to `9` as a ASCII Code.<br/>数値文字列を判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `0` ~ `9` の範囲にあるかどうかを判定します． |
| isAlphabet()  | A function that judges if a string is configured by alphabet. Determine if a character or all of the string passed to the 1st argument are in the range of `A` to `Z` or `a` to `z` as a ASCII Code.<br/>アルファベット文字列で構成されているかを判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `A` ~ `Z` または `a` ~ `z` の範囲にあるかどうかを判定します． |
| isAlphabet_upper() | A function that judges if a string is configured by uppercase. Determine if a character or all of the string passed to the 1st argument are in the range of `A` to `Z` as a ASCII Code.<br/>大文字のアルファベット文字列で構成されているかを判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `A` ~ `Z` の範囲にあるかどうかを判定します． |
| isAlphabet_lower() | A function that judges if a string is configured by lowercase. Determine if a character or all of the string passed to the 1st argument are in the range of `a` to `z` as a ASCII Code.<br/>小文字のアルファベット文字列で構成されているかを判定する関数．第一引数に渡された全ての文字または文字列が ASCII Code での `a` ~ `z` の範囲にあるかどうかを判定します． |
| charIn()      | A function that judges the inclusion of a particular character. Determine if the character of the 1st argument is included in the string of the 2nd argument.<br>特定の文字を内包するか判定する関数．第一引数の文字が，第二引数の文字列に含まれるかを判定します． |
| strIn()       | A function that judges the inclusion of a particular string. Determine if the string of the 1st argument is included in the string of the 2nd argument.<br>特定の文字列を内包するか判定する関数．第一引数の文字列が，第二引数の文字列に含まれるかを判定します． |

## Usage
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

### charIn(), strIn()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::charIn('c', "abcdef") );
    sstd::printn( sstd::charIn('x', "abcdef") ); printf("\n");
    
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
