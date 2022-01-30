# glob
## Abstract
Functions to search files and directories

## Header file
```cpp
namespace sstd{
    struct pathAndType{
        std::string path;
        char type; // 'f': file, 'd': directory
        
        bool operator < (const struct pathAndType& rhs){
            return (*this).path < rhs.path;
        }
    };
    
    std::vector<std::string> glob(const        char* path, const char* opt);
    std::vector<std::string> glob(const std::string& path, const char* opt);
    std::vector<std::string> glob(const        char* path);
    std::vector<std::string> glob(const std::string& path);
    
    std::vector<struct pathAndType> glob_pt(const        char* path, const char* opt); // _pt: with path type
    std::vector<struct pathAndType> glob_pt(const std::string& path, const char* opt);
    std::vector<struct pathAndType> glob_pt(const        char* path);
    std::vector<struct pathAndType> glob_pt(const std::string& path);
}
```

## Description
| Function name | Description |
| ------------- | ----------- |
| glob()  | `glob` can search file and directory with wildcard (`*` and `?`).<br><br>`glob` は，wildcard (`*` と `?`) を用いた，ファイルとディレクトリを探索できます． |
| glob_pt()  | `glob_pt` is a type of `glob` with a variable indicating the file type in the returning value. Options can take `d`, `f`, `r` and `p`. There options can be specified independently in no particular order.<br>Options:<br>- `d`: getting directory name<br>- `f`: getting file name<br>- `r`: recursive directory<br>- `p`: useing `sstd::pathmatch()` instead of `sstd::strmatch()` internally<br><br>`glob_pt` は，`glob` の戻り値にファイルタイプを示す変数が追加されたバージョンです．オプションには `d`, `f`, `r`, `p` があり，それぞれ独立に，順不同で指定できます． |

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

    std::vector<struct sstd::pathAndType> vPt = sstd::glob_pt("./tmp/*.txt");
    sstd::printn(vPt);

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
    
    std::vector<struct sstd::pathAndType> vPt = sstd::glob_pt("./tmp/*", "dfr");
    sstd::printn(vPt);
    
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

