# hashSum
## Abstract
Functions compatible with the hashSum commands.  
ハッシュ値を計算するコマンドの互換関数です．

## Header file
```cpp
namespace sstd{
    std::string vecUint8_to_hexString(const std::vector<uint8>& hash);
    
    std::string md5sum   (const char*        pPath);
    std::string sha1sum  (const char*        pPath);
    std::string sha224sum(const char*        pPath);
    std::string sha256sum(const char*        pPath);
    std::string sha384sum(const char*        pPath);
    std::string sha512sum(const char*        pPath);
    
    std::string md5sum   (const std::string&  path);
    std::string sha1sum  (const std::string&  path);
    std::string sha224sum(const std::string&  path);
    std::string sha256sum(const std::string&  path);
    std::string sha384sum(const std::string&  path);
    std::string sha512sum(const std::string&  path);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| vecUint8_to_hexString() | converts the input binary to to a hexadecimal string.<br>入力されたバイナリを，16 進数表記の文字列に変換します． |
| md5sum()      | returns the result of md5sum calculation as a string. And returns 0 length std::string object when the md5sum() function failed.<br>md5sum の計算結果を文字列で返します．関数が失敗した場合は，長さ 0 の std::string オブジェクトを返却します． |
| sha1sum()     | returns the result of sha1sum calculation as a string. And returns 0 length std::string object when the sha1sum() function failed.<br>sha1sum の計算結果を文字列で返します．関数が失敗した場合は，長さ 0 の std::string オブジェクトを返却します． |
| sha224sum()   | returns the result of sha224sum calculation as a string. And returns 0 length std::string object when the sha224sum() function failed.<br>sha224sum の計算結果を文字列で返します．関数が失敗した場合は，長さ 0 の std::string オブジェクトを返却します． |
| sha256sum()   | returns the result of sha256sum calculation as a string. And returns 0 length std::string object when the sha256sum() function failed.<br>sha256sum の計算結果を文字列で返します．関数が失敗した場合は，長さ 0 の std::string オブジェクトを返却します． |
| sha384sum()   | returns the result of sha384sum calculation as a string. And returns 0 length std::string object when the sha384sum() function failed.<br>sha384sum の計算結果を文字列で返します．関数が失敗した場合は，長さ 0 の std::string オブジェクトを返却します． |
| sha512sum()   | returns the result of sha512sum calculation as a string. And returns 0 length std::string object when the sha512sum() function failed.<br>sha512sum の計算結果を文字列で返します．関数が失敗した場合は，長さ 0 の std::string オブジェクトを返却します． |


## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("head -c 5m /dev/urandom > ./tmp/rand.bin"); // generate 5 MB random file
    
    sstd::printn( sstd::sha256sum("./tmp/rand.bin") );
    
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
- Source: [sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/hashSum.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/hashSum.cpp)
- Header: [sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/math/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp)
- Test: [test/math/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/math/hashFnc_of_MD5_SHA1_SHA2/hashSum.hpp)

