# read / write
## Abstract
Functions for reading and writing files.  
ファイルの読み書きに利用する関数．

## Header file
```cpp
namespace sstd{
    bool read_bin(std::vector<uint8>& ret, const char*        path);
    bool read_bin(std::vector<uint8>& ret, const std::string& path);
    std::vector<uint8> read_bin(const char*        path);
    std::vector<uint8> read_bin(const std::string& path);
    
    bool write_bin(const char*        path, std::vector<uint8>& rhs);
    bool write_bin(const std::string& path, std::vector<uint8>& rhs);
    
    std::string read(const char*        path);
    std::string read(const std::string& path);
    bool read_woBOM(std::string& ret_str, const char*        path); // wo: without
    bool read_woBOM(std::string& ret_str, const std::string& path); // wo: without
    
    size_t write(const        char* path, const void* ptr, const size_t type_size, const size_t num); // (1)
    size_t write(const std::string& path, const void* ptr, const size_t type_size, const size_t num); // (2)
    size_t write(const        char* path, const std::string& s);                                      // (3)
    size_t write(const std::string& path, const        char* s);                                      // (4)
    size_t write(const std::string& path, const std::string& s);                                      // (5)
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Below functions are the not recommended to use. (Below functions will be delete on sstd ver 3.x.x).

namespace sstd{
    std::string read_withoutBOM(const char*        path);
    std::string read_withoutBOM(const std::string& path);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
```

## Description
| Function name | Description |
| ------------- | ----------- |
| read_bin()    | <br> |
| write_bin()   | <br> |
| read()        | <br> |
| read_woBOM()  | returns string without BOM. <br>BOM を取り除いた文字列を std::string として返却します． |
| write()       | <br> |

## Usage
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    std::string f_path = "./tmp/test_read_write.txt";
    
    std::string s = "abcdef\nGHIJK";
    size_t w_size = sstd::write(f_path, s);
    sstd::printn(w_size);
    
    std::string s_read = sstd::read(f_path);
    sstd::printn(s_read.size());
    sstd::printn(s_read);
    
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/read_write.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/read_write.cpp)
- Header: [sstd/src/file/read_write.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/read_write.hpp)
- Test: [test/src_test/file/read_write.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/read_write.cpp)
  (Not implemented yet)

