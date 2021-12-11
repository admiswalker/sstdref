# csv
## Abstract
- `csv2vvec()`  
  Parseing CSV file to `std::vector<std::vector<std::string>>`.  
  CSV ファイルをパースして `std::vector<std::vector<std::string>>` に変換します.

- `vvec2csv()`  
  Converting `std::vector<std::vector<std::string>>` to CSV file.  
  `std::vector<std::vector<std::string>>` を CSV ファイルに変換します.

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
- <u>**example.csv**</u>
```
#mdEx: cpp example (in:attachment:example.csv)
a, bcd
"hello, world", "efg"
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    std::vector<std::vector<std::string>> vv = sstd::csv2vvec("example.csv");
    sstd::printn( vv );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### vvec2csv()
- <u>**main.cpp**</u>
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
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix
### CSV with header (string)
Below C++ code gets string CSV data removing header descriptions.  
下記の C++ コードは，説明ヘッダを取り除いた文字列の CSV データを取得します．

#### CSV example  
Range of Integers

| Type name | Bytes | Range of values |
| --------- | ----- | --------------- |
| int8_t    | 1     | -128 ~ 127      |
| int16_t   | 2     | -32,768 ~ 32,767 |
| int32_t   | 4     | -2,147,483,648 ~ 2,147,483,647 |
| int64_t   | 8     | -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 |

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    {
        // write to CSV
        
        sstd::vvec<std::string> header = { // sstd::vvec<T> is same as a std::vector<std::vector<T>>.
            {"Type name", "Bytes", "Range of values"}
        };
        sstd::vvec<std::string> vvTable = {
            {"int8_t", "1", "-128 ~ 127"}, 
            {"int16_t", "2", "-32,768 ~ 32,767"}, 
            {"int32_t", "4", "-2,147,483,648 ~ 2,147,483,647"}, 
            {"int64_t", "8", "-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807"}
        };
        sstd::vvec<std::string> vv = header << vvTable;
        sstd::vvec2csv("./tmp/example.csv", vv);
    }
    {
        // Read from CSV
        
        sstd::vvec<std::string> vvecOrig = sstd::csv2vvec("./tmp/example.csv");
        sstd::vvec<std::string> header   = vvecOrig && sstd::slice_mv(sstd::begin(), 1);
        sstd::vvec<std::string> vvS      = vvecOrig && sstd::slice_mv(1, sstd::end());
        sstd::printn(vvS);
    }
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### CSV with header (double)
Below C++ code gets floating points CSV data removing header descriptions.  
下記の C++ コードは，説明ヘッダを取り除いた浮動小数点数の CSV データを取得します．

#### CSV example  
sin(Πx) and cos(Πx)

| x    | sin(πx) | cos(πx) |
| ---- | ------- | ------- |
| 0.00 |  0.00   |  1.00   |
| 0.10 |  0.31   |  0.95   |
| 0.20 |  0.59   |  0.81   |
| 0.30 |  0.81   |  0.59   |
| 0.40 |  0.95   |  0.31   |
| 0.50 |  1.00   |  0.00   |
| 0.60 |  0.95   | -0.31   |
| 0.70 |  0.81   | -0.59   |
| 0.80 |  0.59   | -0.81   |
| 0.90 |  0.31   | -0.95   |
| 1.00 |  0.00   | -1.00   |
| 1.10 | -0.31   | -0.95   |
| 1.20 | -0.59   | -0.81   |
| 1.30 | -0.81   | -0.59   |
| 1.40 | -0.95   | -0.31   |
| 1.50 | -1.00   |  0.00   |
| 1.60 | -0.95   |  0.31   |
| 1.70 | -0.81   |  0.59   |
| 1.80 | -0.59   |  0.81   |
| 1.90 | -0.31   |  0.95   |
| 2.00 |  0.00   |  1.00   |

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    {
        // write to CSV
        
        sstd::vvec<std::string> header = { // sstd::vvec<T> is same as a std::vector<std::vector<T>>.
            {"x", "sin(πx)", "cos(πx)"}
        };
        std::vector<double> vX   = {0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90, 1.00, 1.10, 1.20, 1.30, 1.40, 1.50, 1.60, 1.70, 1.80, 1.90, 2.00};
        std::vector<double> vSin = {0.00, 0.31, 0.59, 0.81, 0.95, 1.00, 0.95, 0.81, 0.59, 0.31, 0.00, -0.31, -0.59, -0.81, -0.95, -1.00, -0.95, -0.81, -0.59, -0.31, 0.00};
        std::vector<double> vCos = {1.00, 0.95, 0.81, 0.59, 0.31, 0.00, -0.31, -0.59, -0.81, -0.95, -1.00, -0.95, -0.81, -0.59, -0.31, 0.00, 0.31, 0.59, 0.81, 0.95, 1.00};
        sstd::vvec<double> vvD = {{vX}, {vSin}, {vCos}};
        sstd::vvec<double> vvTable = sstd::Tr( vvD );
        /*
        // up is same as a below.
        sstd::vvec<double> vvTable = {
            {0.00,  0.00,  1.00},
            {0.10,  0.31,  0.95},
            {0.20,  0.59,  0.81},
            {0.30,  0.81,  0.59},
            {0.40,  0.95,  0.31},
            {0.50,  1.00,  0.00},
            {0.60,  0.95, -0.31}, 
            {0.70,  0.81, -0.59}, 
            {0.80,  0.59, -0.81}, 
            {0.90,  0.31, -0.95}, 
            {1.00,  0.00, -1.00}, 
            {1.10, -0.31, -0.95}, 
            {1.20, -0.59, -0.81}, 
            {1.30, -0.81, -0.59}, 
            {1.40, -0.95, -0.31}, 
            {1.50, -1.00,  0.00}, 
            {1.60, -0.95,  0.31}, 
            {1.70, -0.81,  0.59}, 
            {1.80, -0.59,  0.81}, 
            {1.90, -0.31,  0.95}, 
            {2.00,  0.00,  1.00}
        };*/
        sstd::vvec<std::string> vv = header << sstd::double2str(vvTable);
        sstd::vvec2csv("./tmp/example.csv", vv);
    }
    {
        // Read from CSV
        
        sstd::vvec<std::string> vvecOrig = sstd::csv2vvec("./tmp/example.csv");
        sstd::vvec<std::string> header   = vvecOrig && sstd::slice_mv(sstd::begin(), 1);
        sstd::vvec<std::string> vvS      = vvecOrig && sstd::slice_mv(1, sstd::end());
        sstd::vvec<     double> vvD      = sstd::Tr(sstd::str2double(vvS));
        sstd::printn(header);
        sstd::printn(vvD[0]);
        sstd::printn(vvD[1]);
        sstd::printn(vvD[2]);
    }
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/csv.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/csv.cpp)
- Header: [sstd/src/file/csv.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/csv.hpp)
- Test: [test/file/csv.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/csv.hpp)
  (Not implemented yet)

