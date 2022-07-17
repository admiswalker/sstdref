# hashSum
## Abstract
Functions compatible with the hashSum commands.  
ハッシュ値を計算するコマンドの互換関数です．

## Header file
```cpp
namespace sstd{
    std::string vecUint8_to_hexString(const std::vector<uint8>& hash);
    
    bool md5sum   (std::string& ret, const char*        pPath);
    bool sha1sum  (std::string& ret, const char*        pPath);
    bool sha224sum(std::string& ret, const char*        pPath);
    bool sha256sum(std::string& ret, const char*        pPath);
    bool sha384sum(std::string& ret, const char*        pPath);
    bool sha512sum(std::string& ret, const char*        pPath);
    
    bool md5sum   (std::string& ret, const std::string&  path);
    bool sha1sum  (std::string& ret, const std::string&  path);
    bool sha224sum(std::string& ret, const std::string&  path);
    bool sha256sum(std::string& ret, const std::string&  path);
    bool sha384sum(std::string& ret, const std::string&  path);
    bool sha512sum(std::string& ret, const std::string&  path);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| md5sum()      |  |
| sha1sum()     |  |
| sha224sum()   |  |
| sha256sum()   |  |
| sha384sum()   |  |
| sha512sum()   |  |


## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("head -c 5m /dev/urandom > ./tmp/rand.bin"); // generate 5 MB random file
    
    bool tf; std::string s; tf = sstd::sha256sum(s, "./tmp/rand.bin");
    sstd::printn( tf );
    sstd::printn( s );
    printf("\n");
    fflush(stdout);
    
    sstd::system("sha256sum ./tmp/rand.bin");
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/hashFnc_of_MD5_SHA1_SHA2/hashSum.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/hashFnc_of_MD5_SHA1_SHA2/hashSum.cpp)
- Header: [sstd/src/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp)
- Test: [test/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp)
  (Not implemented yet)

