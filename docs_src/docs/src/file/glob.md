# glob
## Abstract
`glob` can search file and directory with `*` and `?`. (The other regular expressions are not implimented).
`glob` は，正規表現 `*` や `?` により，ファイルやディレクトリを探索します．  
※その他の正規表現については，現状未実装です．

Options can take `d`, `f` and `r`. There options can be specified independently in no particular order.
オプションには `d`, `f`, `r` があり，それぞれ独立に，順不同で指定できます．

- Options
    - `d`: getting directory name option
    - `f`: getting file name option
    - `r`: recursive directory option

## Header file
```cpp
namespace sstd{
    std::vector<std::string> glob(const        char* path, const char* opt);
    std::vector<std::string> glob(const std::string& path, const char* opt);
    std::vector<std::string> glob(const        char* path);
    std::vector<std::string> glob(const std::string& path);
}
```

## Usage01: getting only file without recursive option
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("touch ./tmp/a.txt");
    sstd::system("touch ./tmp/b.csv");
    sstd::system("touch ./tmp/c.txt");
    
    std::vector<std::string> vStr = sstd::glob("./tmp/*.txt");
    sstd::printn(vStr);
    
    sstd::rm("./tmp");
}
```
- <u>**example.txt**</u>
```
#mdEx: cpp example (out)
```

## Usage02: getting file and directory with recursive option
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::mkdir("./tmp/a");
    sstd::mkdir("./tmp/b");
    sstd::mkdir("./tmp/c");
    sstd::system("touch ./tmp/a.txt");
    sstd::system("touch ./tmp/b.csv");
    sstd::system("touch ./tmp/c.txt");
    
    std::vector<std::string> vStr = sstd::glob("./tmp/*", "dfr");
    sstd::printn(vStr);
    
    sstd::rm("./tmp");
}
```
- <u>**example.txt**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/file/glob.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/glob.cpp)
- Header: [sstd/src/file/glob.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/file/glob.hpp)
- Test: [test/file/glob.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/file/glob.hpp)

