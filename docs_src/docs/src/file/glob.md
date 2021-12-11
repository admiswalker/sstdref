# glob
## Abstract
`glob` は，正規表現 `*` により，ディレクトリを探索します．  
※その他の正規表現については，現状未実装です．

## Header file
```cpp
namespace sstd{
    std::vector<std::string> glob(const        char* path);
    std::vector<std::string> glob(const std::string& path);
}
```

## Usage
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

## Implementation
- Source: [sstd/src/glob.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/glob.cpp)
- Header: [sstd/src/glob.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/glob.hpp)
- Test: [test/glob.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/glob.hpp)

