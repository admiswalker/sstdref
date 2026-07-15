
- input
```cpp
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
argc = 1
argv[i] = "./a.out"

```

- input
```cpp
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
$ ./a.out
argc = 1
argv[i] = "./a.out"

```

- input
```cpp
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
$ ./a.out arg1 arg2 arg3
argc = 4
argv[i] = "./a.out"
argv[i] = "arg1"
argv[i] = "arg2"
argv[i] = "arg3"

```

- input
```cpp
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
$ ./a.out arg4 arg5 arg6
argc = 4
argv[i] = "./a.out"
argv[i] = "arg4"
argv[i] = "arg5"
argv[i] = "arg6"
$ ./a.out arg7 arg8 arg9
argc = 4
argv[i] = "./a.out"
argv[i] = "arg7"
argv[i] = "arg8"
argv[i] = "arg9"

```
