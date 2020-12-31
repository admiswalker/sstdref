title: What is SSTD ?

<style>
    .img_overlay { /* parent div */
        position: relative;
    }
    .img_overlay p {
         position: absolute;
         font-size: 40px;
         font-weight: normal;
         color: white; /* string color */
         top: 0;
         left: 0;
         margin:0;
         padding:0;
         margin-top:-5px;
    }
    .img_overlay img {
         width: 100%;
    }
</style>
<div class="img_overlay">
  <p>SubStandardLibrary</p>	
  <img src="./ADMIS_Walker_Ver2017_05_30.JPG" />
</div>
<div style="margin-top:35px;"></div>


# What is SSTD ?
<div style="margin-top:-30px;"></div>
SubStandardLibrary (SSTD) is a convenient functions set for C++, works on GCC (g++).


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
- MIT licence or Public domain.  
  (This software is dual license, so you can choose whichever you want).

## Repository
- Source code: [github.com/admiswalker/SubStandardLibrary](https://github.com/admiswalker/SubStandardLibrary)
- Documentation: [github.com/admiswalker/sstdref](https://github.com/admiswalker/sstdref)
