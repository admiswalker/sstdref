# SHA-2 (224, 256, 384, 512 bits)
## Abstract
```sha224()```, ```sha256()```, ```sha384()``` and ```sha512()``` calculate SHA-2 cryptographic hash function.  
```sha224()```, ```sha256()```, ```sha384()``` および ```sha512()``` は暗号学的ハッシュ関数である SHA-2 を計算します．

## Header file
```cpp
namespace sstd{
    std::vector<uint8> sha224(const uchar* in, size_t in_len);
    std::vector<uint8> sha256(const uchar* in, size_t in_len);
    std::vector<uint8> sha384(const uchar* in, size_t in_len);
    std::vector<uint8> sha512(const uchar* in, size_t in_len);
    
    std::vector<uint8> sha224(const std::vector<uint8>& in);
    std::vector<uint8> sha256(const std::vector<uint8>& in);
    std::vector<uint8> sha384(const std::vector<uint8>& in);
    std::vector<uint8> sha512(const std::vector<uint8>& in);
}
```

## Usage
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

std::string uint8_to_str(const std::vector<uint8>& v){
    std::string s;
    for(uint i=0; i<v.size(); ++i){ s += sstd::ssprintf("%02x", (int)v[i]); }
    return s;
}

int main(){
    sstd::mkdir("./tmp");
    sstd::system("head -c 5m /dev/urandom > ./tmp/rand.txt"); // generate 5 MB random file
    sstd::system("sha224sum ./tmp/rand.txt");
    
    std::vector<uint8> vBin = sstd::readAll_bin("./tmp/rand.txt"); // read all as a binary
    std::string sha224_str = uint8_to_str( sstd::sha224( vBin ) );
    sstd::printn( sha224_str );
    
    sstd::rm("./tmp");
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.cpp)
- Header: [sstd/src/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.hpp)
- Test: [test/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.hpp)
  (Not implemented yet)

