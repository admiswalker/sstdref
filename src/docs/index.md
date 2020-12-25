# What is SSTD ?

SubStandardLibrary (SSTD) is a convenient functions set for C++, works on GCC(g++).

## Installation
1. Downloading source code from [github.com/admiswalker/SubStandardLibrary](https://github.com/admiswalker/SubStandardLibrary).
2. Copying all of under ```./sstd/*.```
3. Compilling the sstd.
   ```
   $ cd ./sstd
   $ make
   ```
4. Adding flags in your makefile.
   ```
   CFLAGS += -I./sstd/include -L./sstd/lib -lsstd
   CFLAGS += -std=gnu++0x
   ```
5. Including a header ```#include <sstd/sstd.hpp>``` in your code.

## License
- MIT licence or Public domain. (This software is dual license, so you can choose whichever you want).

## Repository
- [github.com/admiswalker/SubStandardLibrary](https://github.com/admiswalker/SubStandardLibrary)
