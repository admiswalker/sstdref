# SHA-1
## Abstract
`sha1()` calculate SHA-1 cryptographic hash function.  
`sha1()` は暗号学的ハッシュ関数である SHA-1 を計算します．

## Header file
```cpp
namespace sstd{
    std::vector<uint8> sha1(const uchar* in, size_t in_len);
    std::vector<uint8> sha1(const std::vector<uint8>& in);
}
```

## Usage
- <u>**main.cpp**</u>
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
    sstd::system("sha1sum ./tmp/rand.txt");
    
    std::vector<uint8> vBin = sstd::read_bin("./tmp/rand.txt"); // read all as a binary
    std::string md5_str = uint8_to_str( sstd::sha1( vBin ) );
    sstd::printn( md5_str );
    
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.cpp)
- Header: [sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.hpp)
- Test: [test/src_test/math/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/math/hashFnc_of_MD5_SHA1_SHA2/sstd_md5_sha1_sha2_wrapper.cpp)

