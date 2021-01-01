# strmatch
## Abstract
```strmatch.hpp``` contains string comparision functions.  
```strmatch.hpp``` は文字列比較関数を収録しています．

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
    
    bool isNum               (char rhs);
    bool isAlphabet          (char rhs);
    bool isAlphabet_onlyUpper(char rhs);
    bool isAlphabet_onlyLower(char rhs);
}
```

## Usage
### strmatch(), strmatch_getWC()
- input
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
- output  
```
#mdEx: cpp example (out)
```

### isNum(), isAlphabet(), isAlphabet_onlyUpper(), isAlphabet_onlyLower()
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::printn( sstd::isNum('0') );
    sstd::printn( sstd::isNum('A') );
    sstd::printn( sstd::isNum('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet('0') );
    sstd::printn( sstd::isAlphabet('A') );
    sstd::printn( sstd::isAlphabet('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_onlyUpper('0') );
    sstd::printn( sstd::isAlphabet_onlyUpper('A') );
    sstd::printn( sstd::isAlphabet_onlyUpper('a') ); printf("\n");
    
    sstd::printn( sstd::isAlphabet_onlyLower('0') );
    sstd::printn( sstd::isAlphabet_onlyLower('A') );
    sstd::printn( sstd::isAlphabet_onlyLower('a') ); printf("\n");
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/strmatch.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strmatch.cpp)
- Header: [sstd/src/strmatch.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/strmatch.hpp)
- Test: [test/strmatch.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/strmatch.hpp)
