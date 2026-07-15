
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){
    sstd::printn(argc);
    for(int i=0; i<argc; ++i){
        sstd::printn(argv[i]);
    }
}
```
- output
```
#mdEx: cpp example (out)
```

- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){
    sstd::printn(argc);
    for(int i=0; i<argc; ++i){
        sstd::printn(argv[i]);
    }
}
```
- output
```
#mdEx: cpp example (out)
$ ./a.out
```

- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){
    sstd::printn(argc);
    for(int i=0; i<argc; ++i){
        sstd::printn(argv[i]);
    }
}
```
- output
```
#mdEx: cpp example (out)
$ ./a.out arg1 arg2 arg3
```

- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(int argc, char *argv[]){
    sstd::printn(argc);
    for(int i=0; i<argc; ++i){
        sstd::printn(argv[i]);
    }
}
```
- output
```
#mdEx: cpp example (out)
$ ./a.out arg4 arg5 arg6
$ ./a.out arg7 arg8 arg9
```
