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
SubStandardLibrary (SSTD) is a convenient functions-set for the C++ which the author wished that the standard library has these convenient functions. This library works on the GCC (g++) on the Ubuntu OS.  
SubStandardLibrary (SSTD) は，著者が標準ライブラリにあって欲しかったと思う便利な関数群を収録した C++ 向けのライブラリです．Ubuntu OS 上の GCC (g++) で動作します．


## Installation
1. Downloading source code from [github.com/admiswalker/SubStandardLibrary](https://github.com/admiswalker/SubStandardLibrary).  
   ソースコードを [github.com/admiswalker/SubStandardLibrary](https://github.com/admiswalker/SubStandardLibrary) からダウンロードします．
2. Copying the `./sstd` directory to the project directory  
   `./sstd` ディレクトリを対象のプロジェクトディレクトリ下へコピーします．
3. Compilling the sstd according to the commands below.  
   下記のコマンドに従い sstd をコンパイルします．
   ```
   $ cd ./sstd
   $ make
   ```
4. Adding paths to the sstd as a compilation option in the makefile using sstd.  
   sstd へのパスをコンパイルオプションとして makefile に追加します．
   ```
   CFLAGS += -I./sstd/include -L./sstd/lib -lsstd
   CFLAGS += -std=gnu++0x
   ```
5. Including the `#include <sstd/sstd.hpp>` header in your code.  
   `#include <sstd/sstd.hpp>` ヘッダをコードから読み込みます．

## License
- MIT licence or Public domain.  
  (This software is dual license, so you can choose whichever you want).
- MIT licence またはパブリックドメイン．（このソフトウェアはデュアルライセンスのため，好きな方を選んでよい）．

## Repository
- Source code: [github.com/admiswalker/SubStandardLibrary](https://github.com/admiswalker/SubStandardLibrary)
- Documentation: [github.com/admiswalker/sstdref](https://github.com/admiswalker/sstdref)
