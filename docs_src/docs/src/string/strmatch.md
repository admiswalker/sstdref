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
    
    bool isNum               (const char rhs);
    bool isNum               (const char* rhs);
    bool isNum               (const std::string& rhs);
    
    bool isAlphabet          (const char rhs);
    bool isAlphabet          (const char* rhs);
    bool isAlphabet          (const std::string& rhs);
    
    bool isAlphabet_onlyUpper(const char rhs);
    bool isAlphabet_onlyUpper(const char* rhs);
    bool isAlphabet_onlyUpper(const std::string& rhs);
    
    bool isAlphabet_onlyLower(const char rhs);
    bool isAlphabet_onlyLower(const char* rhs);
    bool isAlphabet_onlyLower(const std::string& rhs);
    
    bool charIn(const char lhs, const        char* rhs); // Is lhs in rhs ?
    bool charIn(const char lhs, const std::string& rhs); // Is lhs in rhs ?
    
    bool strIn(const char*        lhs, const char*        rhs); // is lhs in rhs ? (is rhs include lhs ?)
    bool strIn(const char*        lhs, const std::string& rhs);
    bool strIn(const std::string& lhs, const char*        rhs);
    bool strIn(const std::string& lhs, const std::string& rhs);
}
```

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

### isAlphabet_onlyUpper()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isAlphabet_onlyUpper('0') );
    sstd::printn( sstd::isAlphabet_onlyUpper('A') );
    sstd::printn( sstd::isAlphabet_onlyUpper('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_onlyUpper("0123456789") );
    sstd::printn( sstd::isAlphabet_onlyUpper("ABCDEFGHIJ") );
    sstd::printn( sstd::isAlphabet_onlyUpper("abcdeABCDE") ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_onlyUpper(std::string("0123456789")) );
    sstd::printn( sstd::isAlphabet_onlyUpper(std::string("ABCDEFGHIJ")) );
    sstd::printn( sstd::isAlphabet_onlyUpper(std::string("abcdeABCDE")) ); printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### isAlphabet_onlyLower()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isAlphabet_onlyLower('0') );
    sstd::printn( sstd::isAlphabet_onlyLower('A') );
    sstd::printn( sstd::isAlphabet_onlyLower('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_onlyLower("0123456789") );
    sstd::printn( sstd::isAlphabet_onlyLower("abcdeABCDE") );
    sstd::printn( sstd::isAlphabet_onlyLower("abcdefghij") ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_onlyLower(std::string("0123456789")) );
    sstd::printn( sstd::isAlphabet_onlyLower(std::string("abcdeABCDE")) );
    sstd::printn( sstd::isAlphabet_onlyLower(std::string("abcdefghij")) ); printf("\n");
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
