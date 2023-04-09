# mv
## Abstract
Function to move file and directory

## Header file
```cpp
namespace sstd{
    bool mv  (const char*        pPath_src, const char*        pPath_dst);
    bool mv  (const std::string&  path_src, const char*        pPath_dst);
    bool mv  (const char*        pPath_src, const std::string&  path_dst);
    bool mv  (const std::string&  path_src, const std::string&  path_dst);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| mv()  | A function to move file and directory from src-path to dst-path.<br>ファイルやディレクトリを src-path から dst-path へ移動させる関数． |

## Usage
### move file to file
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp/01");
    sstd::mkdir("./tmp/02");
    sstd::system("touch ./tmp/01/example.txt");
    
    sstd::mv("./tmp/01/example.txt", "./tmp/02/example.txt");
    
    printf("./tmp/01: \n    "); fflush(stdout); sstd::system("ls ./tmp/01"); printf("\n");
    printf("./tmp/02: \n    "); fflush(stdout); sstd::system("ls ./tmp/02");
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### move file to directory
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp/01");
    sstd::mkdir("./tmp/02");
    sstd::system("touch ./tmp/01/example.txt");
    
    sstd::mv("./tmp/01/example.txt", "./tmp/02");
    
    printf("./tmp/01: \n    "); fflush(stdout); sstd::system("ls ./tmp/01"); printf("\n");
    printf("./tmp/02: \n    "); fflush(stdout); sstd::system("ls ./tmp/02");
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### move directory to directory
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp/01");
    sstd::mkdir("./tmp/02");
    sstd::system("touch ./tmp/01/example.txt");
    
    sstd::mv("./tmp/01", "./tmp/02");
    
    printf("./tmp/01: \n    "); fflush(stdout); sstd::system("ls ./tmp/01"); printf("\n");
    printf("./tmp/02: \n    "); fflush(stdout); sstd::system("ls ./tmp/02");
    sstd::rm("./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/mv.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/mv.cpp)
- Header: [sstd/src/file/mv.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/mv.hpp)
- Test: [test/src_test/file/mv.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/file/mv.cpp)

