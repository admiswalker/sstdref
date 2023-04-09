# system
## Abstract
`system()` executes the specified command.  
`system()` は指定されたコマンドを実行します．

## Header file
```cpp
namespace sstd{
    int system(const        char* cmd);
    int system(const std::string& cmd);

    int system_stdout(std::string& ret, const        char* cmd);
    int system_stdout(std::string& ret, const std::string& cmd);
    
    int system_stderr(std::string& ret, const        char* cmd);
    int system_stderr(std::string& ret, const std::string& cmd);
    
    int system_stdout_stderr(std::string& ret, const        char* cmd);
    int system_stdout_stderr(std::string& ret, const std::string& cmd);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Below functions are the not recommended to use. (Below functions will be delete on sstd ver 3.x.x).

namespace sstd{
    std::string system_stdout(const        char* cmd);
    std::string system_stdout(const std::string& cmd);
    
    std::string system_stderr(const        char* cmd);
    std::string system_stderr(const std::string& cmd);
    
    std::string system_stdout_stderr(const        char* cmd);
    std::string system_stdout_stderr(const std::string& cmd);
}
//-----------------------------------------------------------------------------------------------------------------------------------------------
```

## Usage
### system
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::system("mkdir -p ./tmp/a/b/c");
    sstd::system("tree ./tmp");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### system_stdout_stderr
Acquires the `stdout` and `stderr` that accompany the execution result.  
実行結果に伴う標準出力と標準エラー出力を取得します．

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::system("touch hello");
    sstd::system("touch system_stdout_stderr");

    int ret;
    std::string ret_s;
    ret = sstd::system_stdout_stderr(ret_s, "ls");
    sstd::printn( WEXITSTATUS(ret) );
    sstd::printn( ret_s );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/sys/system.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/sys/system.cpp)
- Header: [sstd/src/sys/system.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/sys/system.hpp)
- Test: [test/src_test/sys/system.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/sys/system.cpp)
