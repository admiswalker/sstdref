# csv
## Abstract
- ```csv2vvec()```  
  Parseing CSV file to ```std::vector<std::vector<std::string>>```.  
  CSV ファイルをパースして ```std::vector<std::vector<std::string>>``` に変換します.

- ```vvec2csv()```  
  Converting ```std::vector<std::vector<std::string>>``` to CSV file.  
  ```std::vector<std::vector<std::string>>``` を CSV ファイルに変換します.

## Header file
```cpp
namespace sstd{
    std::vector<std::vector<std::string>> csv2vvec(const        char* pReadFile);
    std::vector<std::vector<std::string>> csv2vvec(const std::string&  readFile);
    
    bool vvec2csv(const        char* pSavePath, const std::vector<std::vector<std::string>>& vecCSV);
    bool vvec2csv(const std::string&  savePath, const std::vector<std::vector<std::string>>& vecCSV);
}
```

## Usage
### csv2vvec()
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system(R"(echo 'a, bcd\n"hello, world", "efg"' > ./tmp/example.csv)");
    printf("$ cat ./tmp/example.csv\n"); fflush(stdout); sstd::system("cat ./tmp/example.csv");
    printf("\n");
    
    std::vector<std::vector<std::string>> vv = sstd::csv2vvec("./tmp/example.csv");
    sstd::printn( vv );
    
    sstd::rm("./tmp");
}
```
- output  
```
#mdEx: cpp example (out)
```

### vvec2csv()
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    
    std::vector<std::vector<std::string>> vv = {{"a", "bcd"}, {"hello, world", "efg"}};
    sstd::vvec2csv("./tmp/example.csv", vv);
    
    printf("$ cat ./tmp/example.csv\n"); fflush(stdout); sstd::system("cat ./tmp/example.csv");
    
    sstd::rm("./tmp");
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/csv.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/csv.cpp)
- Header: [sstd/src/file/csv.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/csv.hpp)
- Test: [test/file/csv.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/csv.hpp)
  (Not implemented yet)

