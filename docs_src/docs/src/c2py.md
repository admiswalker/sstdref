# c2py
## Abstract
`c2py()` calls any Python functions with built-in, `std::vector<T>`, `sstd::mat_c<T>` and `sstd::mat_r<T>` (`T` is limited by built-in types.) types of arguments from 2 lines of C++ codes.  
Data is sharing by the `tmp` directory.

`c2py()` は built-in 型，`std::vector<T>` 型, `sstd::mat_c<T>` 型，および `sstd::mat_r<T>` 型 (ただし，`T` は built-in 型に制限される．) を引数に持つ Python 関数を 2 行の C++ コードで呼び出します．
データは `tmp` ディレクトリにより共有されます．

## Header file
```cpp
namespace sstd{
    template<typename T> class c2py;
}

template<typename T>
class sstd::c2py{
public:
    c2py(const char* temporarilyDir,
         const char* importFile,
         const char* functionName,
         const char* format);
    ~c2py();

    template<typename... ARGS>
    T operator()(ARGS... args);
};
```

- c2py interface
```cpp
sstd::c2py<ATypeOfReturnValue> FunctionName(
    "Tempolary directory",                               // Argument 1
    "A name of calling .py file (without extension)",    // Argument 2
    "A function name calling from .py file",             // Argument 3
    "Arguments types specification of Python function"); // Argument 4
```

- c2py インターフェースの設計
```cpp
sstd::c2py<戻り値の型> 関数名(
    "一時ディレクトリ",                            // 第 1 引数
    "呼び出し先の .py ファイル (ただし拡張子を除く)", // 第 2 引数
    ".py ファイル中から呼び出す関数名",             // 第 3 引数
    "Python 関数の型指定");                      // 第 4 引数
```

## Requirements
`c2py()` requires the `importlib`, `inspect`, `itertools`, `numpy`, `os` and `sys` Python packages. See [sstd/src/c2py.py](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/c2py.py) for details.

`c2py()` は，`importlib`, `inspect`, `itertools`, `numpy`, `os`, `sys` の Python パッケージを必要とします．詳細は [sstd/src/c2py.py](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/c2py.py) を参照すること．


## List of corresponding types. (対応する型の一覧)
Table 1. shows the correspondence between the types on the C ++ side and the types on the Python side.
Table 2. shows a list of type names given when specifying a type on the C ++ side.
If not specifying type on the Python side, numpy will be selected.
And selecting the conversion symbol `~`, the numpy type will be converted to the built-in type.
The c2py is basically processed by numpy, because of the binary compatibility between C++ and Python, 
type conversion of numpy to built-in type will be overhead.

表 1. に C++ 側の型と，Python 側の型との対応を示す．
表 2. に C++ 側の型を指定する際に与える型名の一覧を示す．
Python 側の型について，何も指定しない場合は，numpy 型が選択され，変換記号 `~` を指定することで，built-in 型に変換される．
c2py 上の処理は，C++ とのバイナリ互換性の問題から，基本的に numpy 型で行われるため，built-in 型への変換は，オーバーヘッドとなる．

<!-- ---------------------------------------------------------- -->
<div align="center">
<table style="border-collapse: collapse; font-size: 13px; width: 100%;">
  <caption>Table 1. Correspondence between types implemented in c2py and Python<br/>表 1. c2py で実装されている型と Python 型との対応</caption>
  <tr>
    <td colspan="5" rowspan="1" style="border-top: solid 1px; text-align: center;">Types of C++ side</td>
    <td colspan="1" rowspan="1" style="border-top: solid 1px; text-align: center;">Types of Python side</td>
  </tr>
  <tr>
    <td style="text-align: center; border-bottom: solid 1px;">&nbsp;</td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/>/ Pointer array</td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;bool</td>
    <td style="text-align: left;">std::vector&lt;bool&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;bool&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;bool&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;char</td>
    <td style="text-align: left;">std::vector&lt;char&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;char&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;char&gt;</td>
    <td style="text-align: center;">built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uchar</td>
    <td style="text-align: left;">std::vector&lt;uchar&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;uchar&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;uchar&gt;</td>
    <td style="text-align: center;">built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int8</td>
    <td style="text-align: left;">std::vector&lt;int8&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;int8&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;int8&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int16</td>
    <td style="text-align: left;">std::vector&lt;int16&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;int16&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;int16&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int32</td>
    <td style="text-align: left;">std::vector&lt;int32&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;int32&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;int32&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int64</td>
    <td style="text-align: left;">std::vector&lt;int64&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;int64&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;int64&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint8</td>
    <td style="text-align: left;">std::vector&lt;uint8&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;uint8&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;uint8&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint16</td>
    <td style="text-align: left;">std::vector&lt;uint16&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;uint16&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;uint16&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint32</td>
    <td style="text-align: left;">std::vector&lt;uint32&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;uint32&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;uint32&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint64</td>
    <td style="text-align: left;">std::vector&lt;uint64&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;uint64&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;uint64&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;float</td>
    <td style="text-align: left;">std::vector&lt;float&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;float&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;float&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;double</td>
    <td style="text-align: left;">std::vector&lt;double&gt;</td>
    <td style="text-align: left;">sstd::mat_c&lt;double&gt;</td>
    <td style="text-align: left;">sstd::mat_r&lt;double&gt;</td>
    <td style="text-align: center;">numpy / built-in</td>
  </tr>
  <tr>
    <td style="text-align: left; border-bottom: solid 1px;"></td>
    <td style="text-align: left; border-bottom: solid 1px;">&nbsp;&nbsp;&nbsp;std::string</td>
    <td style="text-align: left; border-bottom: solid 1px;">std::vector&lt;std::string&gt;</td>
    <td style="text-align: left; border-bottom: solid 1px;">sstd::mat_c&lt;std::string&gt;</td>
    <td style="text-align: left; border-bottom: solid 1px;">sstd::mat_r&lt;std::string&gt;</td>
    <td style="text-align: center; border-bottom: solid 1px;">built-in</td>
  </tr>
</table>
</div>
<!-- ---------------------------------------------------------- -->
<br/>

<!-- ---------------------------------------------------------- -->
<div align="center">
<table style="border-collapse: collapse; text-align: center; font-size: 13px; width: 100%;">
  <caption>Table 2. Type names giving to the 4th argument of c2py.<br/>表 2. c2py の第 4 引数に与える型名．</caption>
  <tr>
    <td colspan="5" rowspan="1" style="border-top: solid 1px; text-align: center;">Types of C++ side</td>
  </tr>
  <tr>
    <td style="text-align: center; border-bottom: solid 1px;">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/>/ Pointer array</td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
    <td style="text-align: center; border-bottom: solid 1px;">Entity / Pointer<br/></td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;bool</td>
    <td style="text-align: left;">vec&lt;bool&gt;</td>
    <td style="text-align: left;">mat_c&lt;bool&gt;</td>
    <td style="text-align: left;">mat_r&lt;bool&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;char</td>
    <td style="text-align: left;">vec&lt;char&gt;</td>
    <td style="text-align: left;">mat_c&lt;char&gt;</td>
    <td style="text-align: left;">mat_r&lt;char&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uchar</td>
    <td style="text-align: left;">vec&lt;uchar&gt;</td>
    <td style="text-align: left;">mat_c&lt;uchar&gt;</td>
    <td style="text-align: left;">mat_r&lt;uchar&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int8</td>
    <td style="text-align: left;">vec&lt;int8&gt;</td>
    <td style="text-align: left;">mat_c&lt;int8&gt;</td>
    <td style="text-align: left;">mat_r&lt;int8&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int16</td>
    <td style="text-align: left;">vec&lt;int16&gt;</td>
    <td style="text-align: left;">mat_c&lt;int16&gt;</td>
    <td style="text-align: left;">mat_r&lt;int16&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int32</td>
    <td style="text-align: left;">vec&lt;int32&gt;</td>
    <td style="text-align: left;">mat_c&lt;int32&gt;</td>
    <td style="text-align: left;">mat_r&lt;int32&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;int64</td>
    <td style="text-align: left;">vec&lt;int64&gt;</td>
    <td style="text-align: left;">mat_c&lt;int64&gt;</td>
    <td style="text-align: left;">mat_r&lt;int64&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint8</td>
    <td style="text-align: left;">vec&lt;uint8&gt;</td>
    <td style="text-align: left;">mat_c&lt;uint8&gt;</td>
    <td style="text-align: left;">mat_r&lt;uint8&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint16</td>
    <td style="text-align: left;">vec&lt;uint16&gt;</td>
    <td style="text-align: left;">mat_c&lt;uint16&gt;</td>
    <td style="text-align: left;">mat_r&lt;uint16&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint32</td>
    <td style="text-align: left;">vec&lt;uint32&gt;</td>
    <td style="text-align: left;">mat_c&lt;uint32&gt;</td>
    <td style="text-align: left;">mat_r&lt;uint32&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;uint64</td>
    <td style="text-align: left;">vec&lt;uint64&gt;</td>
    <td style="text-align: left;">mat_c&lt;uint64&gt;</td>
    <td style="text-align: left;">mat_r&lt;uint64&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;float</td>
    <td style="text-align: left;">vec&lt;float&gt;</td>
    <td style="text-align: left;">mat_c&lt;float&gt;</td>
    <td style="text-align: left;">mat_r&lt;float&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left;"></td>
    <td style="text-align: left;">&nbsp;&nbsp;&nbsp;double</td>
    <td style="text-align: left;">vec&lt;double&gt;</td>
    <td style="text-align: left;">mat_c&lt;double&gt;</td>
    <td style="text-align: left;">mat_r&lt;double&gt;</td>
  </tr>
  <tr>
    <td style="text-align: left; border-bottom: solid 1px;"></td>
    <td style="text-align: left; border-bottom: solid 1px;">&nbsp;&nbsp;&nbsp;str / string</td>
    <td style="text-align: left; border-bottom: solid 1px;">vec&lt;str&gt; / vec&lt;string&gt;</td>
    <td style="text-align: left; border-bottom: solid 1px;">mat_c&lt;str&gt; / mat_c&lt;string&gt;</td>
    <td style="text-align: left; border-bottom: solid 1px;">mat_r&lt;str&gt; / mat_r&lt;string&gt;</td>
  </tr>
</table>
</div>
<!-- ---------------------------------------------------------- -->



## Usage
### Sample1: (Return: "int" / Input: "int" and "const int\*")
- <u>**pyFunction.py**</u>
```python
def plus_a_b(a, b): return a+b
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'def plus_a_b(a, b): return a+b' > ./tmp/pyFunction.py");
    
    sstd::c2py<int> plus_a_b("./tmpDir", "./tmp/pyFunction", "plus_a_b", "int, int, const int*");
    int a=1, b=2;
    int c=plus_a_b(a, &b); // Running Python here
    
    sstd::printn(c);
    sstd::rm("./tmp"); return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### Sample2: (Return: "vec&lt;int&gt;" / Input: "const int\*", "len" and "const vec&lt;int&gt;\*")
- <u>**pyFunction.py**</u>
```python
def plus_vecA_vecB(vecA, vecB): return vecA+vecB
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'def plus_vecA_vecB(vecA, vecB): return vecA+vecB' > ./tmp/pyFunction.py");
    
    sstd::c2py<std::vector<int>> plus_vecA_vecB("./tmpDir", "./tmp/pyFunction", "plus_vecA_vecB", "vec<int>, const int*, len, const vec<int>*");
    int arrA[]={1,2,3};
    std::vector<int> vecB={4,5,6};
    std::vector<int> vecC=plus_vecA_vecB(arrA, 3, &vecB); // Running Python here

    sstd::printn(vecC);
    sstd::rm("./tmp"); return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### Sample3: (Return: "void" / Input: "int\*", "int\*", "len" and "vec&lt;int&gt;\*")
Writing back self multiplied value.  
自己乗算値を書き戻す．

- <u>**pyFunction.py**</u>
```python
def selfMult(a, vecB, vecC):
    a[0]=a[0]*a[0]
    for i in range(len(vecB)): vecB[i]=vecB[i]*vecB[i]
    for i in range(len(vecC)): vecC[i]=vecC[i]*vecC[i]
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'def selfMult(a, vecB, vecC):\n    a[0]=a[0]*a[0]\n    for i in range(len(vecB)): vecB[i]=vecB[i]*vecB[i]\n    for i in range(len(vecC)): vecC[i]=vecC[i]*vecC[i]' > ./tmp/pyFunction.py");
    
    sstd::c2py<void> selfMult("./tmpDir", "./tmp/pyFunction", "selfMult", "void, int*, int*, len, vec<int>*");
    int a=2;
    int arrB[]={3,4,5};
    std::vector<int> vecC={6,7,8};
    selfMult(&a, arrB, 3, &vecC);

    sstd::printn(a);
    printf("arrB[3] = [ "); for(uint i=0; i<3; i++){ printf("%d ", arrB[i]); } printf("]\n");
    sstd::printn(vecC);
    sstd::rm("./tmp"); return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```


### Sample4: Types conversion of numpy to built-in
Conversion types in Python side. Symbols on the right side of "|" (which is a separator symbol between C++ and Python) mean the symbols have effect on the Python side. On the right side of "|" enable to take "*" or "~" and these order have no meaning. (There is no difference between "|*~" and "|~*", so it will work same.)

- *: A symbol have a meaning to convert input value on Python side to a pseudo pointer type (self inclusion list).
- ~: A symbol have a meaning to convert input value on Python side to a built-in type (instead of numpy type).

Python 側で型変換を行う場合．セパレータ記号 "|" の左右は，それぞれ，C++ 側と Python 側を表している．分割記号 "|" の右側の型は "*" または "~" を取ることができ，これは Python 側における変換記号である．このとき，変換記号 "*"，"~" の順序は意味をなさない．(したがって， "|*~" と "|~*" の間に差はなく，同じように動作する．)

- *: Python 側の入力値を擬似ポインタ型 (自己包含リスト) へ変換する．
- ~: Python 側の入力値を（numpy 型の代わりに）組み込み型に変換する．
<br/><br/>

- <u>**pyFunction.py**</u>
```python
def checkTypes(Numpy, builtIn, pNumpy, pBuiltIn):
    print(type(Numpy), Numpy)
    print(type(builtIn), builtIn)
    print(type(pNumpy), pNumpy)
    print(type(pBuiltIn), pBuiltIn)
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'def checkTypes(Numpy, builtIn, pNumpy, pBuiltIn):\n    print(type(Numpy), Numpy)\n    print(type(builtIn), builtIn)\n    print(type(pNumpy), pNumpy)\n    print(type(pBuiltIn), pBuiltIn)' > ./tmp/pyFunction.py");
    
    sstd::c2py<void> checkTypes("./tmpDir", "./tmp/pyFunction", "checkTypes", "void, int, int|~, int|*, int|*~");
    checkTypes(0, 0, 0, 0);
    
    sstd::rm("./tmp"); return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
### Sample5: Writing back with changing the length of std::vector&lt;T&gt;
Writing back with changing the length of `std::vector<T>`. (In order to get value from function, sending address is needed.)  
配列長の変化を含む `std::vector<T>` の書き戻し．(関数から値を受け取るため，アドレスを受け渡している)

- <u>**pyFunction.py**</u>
```python
import numpy as np
def changeLen(pVec1, vec2):
    pVec1[0]=np.append(pVec1[0], 4) # numpy    # numpy is not able to add values without changing address of variables. so we need to treat as a pointer like objects (self inclusion list).
    vec2.append(4)                  # built-in
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'import numpy as np\ndef changeLen(pVec1, vec2):\n    pVec1[0]=np.append(pVec1[0], 4)\n    vec2.append(4)' > ./tmp/pyFunction.py");
    
    sstd::c2py<void> changeLen("./tmpDir", "./tmp/pyFunction", "changeLen", "void, vec<int>*|*, vec<int>*|~");
    std::vector<int> vec1={1,2,3}, vec2={1,2,3};
    changeLen(&vec1, &vec2);

    sstd::printn(vec1);
    sstd::printn(vec2);
    
    sstd::rm("./tmp"); return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
### Sample6
Receiving multiple return values from python side. (※ "ret" which is a symbol of return value, must be continuous in arg 4. Interrupted ret occurs error.)  
Python 側から複数の戻り値を受け取る．(※ 戻り値記号 "ret" は，第 4 引数中で連続している必要がある．不連続な ret はエラーを引き起こす．)

- <u>**pyFunction.py**</u>
```python
def multiRet(): return (9, 9, [1,2,3], [4,5,6])
```
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mkdir("./tmp");
    sstd::system("echo 'def multiRet(): return (9, 9, [1,2,3], [4,5,6])' > ./tmp/pyFunction.py");
    
    sstd::c2py<int> multiRet("./tmpDir", "./tmp/pyFunction", "multiRet", "int, ret int*, ret int*, len, ret vec<int>*");
    int ret0=0;
    int ret1=0;
    int ret2[]={0,0,0};
    std::vector<int> ret3;
    ret0 = multiRet(&ret1, &ret2, 3, &ret3);
    
    sstd::printn(ret0);
    sstd::printn(ret1);
    printf("ret2[3] = [ "); for(uint i=0; i<3; i++){ printf("%d ", ret2[i]); } printf("]\n");
    sstd::printn(ret3);
    
    sstd::rm("./tmp"); return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Appendix
### Application sample 1
As one of the most convenient application, c2py enable to call matplotlib which is a famous graph plot library in python from C++. In the code below, generate sin wave on C++ and write graph by matplotlib in Python.

最も便利な応用の 1 つとして，c2py では，Python で有名なグラフプロットライブラリである matplotlib を C++ から呼び出すことができる．下記のサンプルコードでは，C++ 側で生成した sin 波を，Python ライブラリである matplotlib で描画している．

- <u>**pyFunction.py**</u>
```python
import matplotlib as mpl        # "QXcbConnection: Could not connect to display" への対策
mpl.use('Agg')                  # "QXcbConnection: Could not connect to display" への対策
import matplotlib.pyplot as plt # "QXcbConnection: Could not connect to display" への対策
import matplotlib.ticker as tick

def vec2graph(writeName, vecX, vecY):
    plt.clf()
    fig = plt.figure(figsize=(9, 3)) # アスペクト比の設定
    ax1 = fig.add_subplot(111)
    ax1.plot(vecX, vecY, color='k', linewidth=0.5)
    
    title  = "An example of Plotting a figure of sin wave data generated on C++,\n"
    title += "using matplotlib which is a famous graph plotting library of python. \n"
    title += "\"sstd::c2py()\" convertes a type of std::vector<double> on C++ to  \n"
    title += "numpy array type on Python, and calling a Python function from      \n"
    title += "only 2 lines of C++ code.                                                                    "
    ax1.set_title(title)
    
    ax1.grid(which='minor', linewidth=0.5, linestyle=':',  color='gainsboro')
    ax1.grid(which='major', linewidth=0.5, linestyle='-',  color='silver'    )
    
    ax1.tick_params(pad=5, which='major', direction='in', bottom=True, top=True, left=True, right=True, length=4) # 軸の余白 # which: major tick と minor tick に対して変更を適用 # tick を内側方向に # tick を bottom, top, left, right に付加 # tick width # tick length
    ax1.tick_params(pad=5, which='minor', direction='in', bottom=True, top=True, left=True, right=True, length=2) # 軸の余白 # which: major tick と minor tick に対して変更を適用 # tick を内側方向に # tick を bottom, top, left, right に付加 # tick width # tick length
    
    ax1.set_xlabel("Time [sec]\nFig 1.  0.1 Hz sin wave sampled by 10 Hz, 0-60 sec.")
    ax1.set_xlim(0-1, 60+1)
    ax1.xaxis.set_major_locator(tick.MultipleLocator(5))
    ax1.xaxis.set_minor_locator(tick.MultipleLocator(1))
    
    ax1.set_ylabel("Amplitude")
    ax1.set_ylim(-1.1, 1.1)
    ax1.yaxis.set_major_locator(tick.MultipleLocator(0.5))
    ax1.yaxis.set_minor_locator(tick.MultipleLocator(0.1))
    
    plt.savefig(writeName, bbox_inches="tight")
```
- <u>**main.cpp**</u>
```cpp
#include <sstd/sstd.hpp>

int main(){
    double freq2generate = 0.1; // 0.1 Hz sin wave
    double freq2sample = 10;    // 10 Hz sampling
    uint len=60*10 + 1;         // 60 sec
    std::vector<double> vecY = sstd::sinWave(freq2generate, freq2sample, len);
    std::vector<double> vecX(len); for(uint i=0; i<vecX.size(); i++){ vecX[i]=(double)i*(1/freq2sample); }
    
    sstd::c2py<void> vec2graph("./tmpDir", "pyFunctions", "vec2graph", "void, const char*, vec<double>*, vec<double>*");
    vec2graph("./sin.png", &vecX, &vecY);

    return 0;
}
```
- <u>**Execution result**</u>  
![sin.png](../contents/c2py/sin.png)


### Application sample 2
An example of the additional implementation of `vvec<T>`. Currently, only vvec<double> is available.

追加実装された `vvec<T>` の使用例．現状では，`vvec<double>` のみ利用可能．

- <u>**Python**</u>
```python
def vvec2graph(writeName, vLabel, vvecX, vvecY):
    plt.clf()
    fig = plt.figure(figsize=(8.5, 3)) # アスペクト比の設定
    ax1 = fig.add_subplot(111)
    #cmap = plt.get_cmap("tab10")
    vColor=['black', 'blue', 'red']
    vLineStyle = ['solid', 'solid', 'solid'] # solid, dashed, dashdot, dotted
    for i in range(len(vvecX)):
        #ax1.plot(vvecX[i], vvecY[i], linewidth=0.5, color=cmap(i), linestyle=vLineStyle[i], label=vLabel[i])
        ax1.plot(vvecX[i], vvecY[i], linewidth=0.5, color=vColor[i], linestyle=vLineStyle[i], label=vLabel[i])
    ax1.legend(loc='upper right')
    
    ax1.grid(which='minor', linewidth=0.5, linestyle=':',  color='gainsboro')
    ax1.grid(which='major', linewidth=0.5, linestyle='-',  color='silver'    )
    
    ax1.tick_params(pad=5, which='major', direction='in', bottom=True, top=True, left=True, right=True, length=4) # 軸の余白 # which: major tick と minor tick に対して変更を適用 # tick を内側方向に # tick を bottom, top, left, right に付加 # tick width # tick length
    ax1.tick_params(pad=5, which='minor', direction='in', bottom=True, top=True, left=True, right=True, length=2) # 軸の余白 # which: major tick と minor tick に対して変更を適用 # tick を内側方向に # tick を bottom, top, left, right に付加 # tick width # tick length
    
    ax1.set_xlabel("Time [sec]\nFig 2.  0.1 Hz sin, cos and -cos wave sampled by 10 Hz, 0-60 sec.")
    ax1.set_xlim(0-1, 60+1)
    ax1.xaxis.set_major_locator(tick.MultipleLocator(5))
    ax1.xaxis.set_minor_locator(tick.MultipleLocator(1))
    
    ax1.set_ylabel("Amplitude")
    ax1.set_ylim(-1.1, 1.1)
    ax1.yaxis.set_major_locator(tick.MultipleLocator(0.5))
    ax1.yaxis.set_minor_locator(tick.MultipleLocator(0.1))
    
    plt.legend(loc='best')
    plt.savefig(writeName, bbox_inches="tight") # , dpi=100
```
- <u>**main.cpp**</u>
```cpp
#include <sstd/sstd.hpp>

int main(){
    double freq_generate = 0.1; // 0.1 Hz sin wave
    double freq_sample = 10;    // 10 Hz sampling
    uint len=60*10 + 1;         // 60 sec
    std::vector<double> sinY = sstd::sinWave(freq_generate, freq_sample, len);
    std::vector<double> sinX(len); for(uint i=0; i<sinX.size(); i++){ sinX[i]=(double)i*(1/freq_sample); }
    
    std::vector<double> cosY = sstd::cosWave(freq_generate, freq_sample, len);
    std::vector<double> cosX(len); for(uint i=0; i<cosX.size(); i++){ cosX[i]=(double)i*(1/freq_sample); }
    
    std::vector<std::string> vLabel={"sin", "cos", "-cos"};
    std::vector<std::vector<double>> vvecX={sinX, cosX,    cosX};
    std::vector<std::vector<double>> vvecY={sinY, cosY, -1*cosY};
    
    sstd::c2py<void> vvec2graph(tmpDir, fileName, "vvec2graph", "void, const char*, const vec<str>*, const vvec<double>*, const vvec<double>*");
    vvec2graph("./sin_cos.png", &vLabel, &vvecX, &vvecY);
    
    return 0;
}
```
- <u>**Execution result**</u>  
![sin_cos.png](../contents/c2py/sin_cos.png)

### Application sample 3
In the code below, reading png image from Python, editing on C++ and writing to png file by Python again.

Python 関数から png ファイルを読み込み，C++ で色を編集した後，再度 Python 関数で png ファイルへ書き出すサンプルコードを示す．

- <u>**Python**</u>
```python
import numpy as np
from PIL import Image

def imgPath2mat_rRGB(path):
    imgRaw = Image.open(path)
    imgRGB = imgRaw.split()
    imgR = imgRGB[0]
    imgG = imgRGB[1]
    imgB = imgRGB[2]
    return (imgR, imgG, imgB)

def mat_rRGB2img(path, imgR, imgG, imgB):
    imgCombined = np.dstack((np.dstack((imgR, imgG)), imgB))
    imgPIL      = Image.fromarray(imgCombined)
    imgPIL.save(path)
```
- <u>**main.cpp**</u>
```cpp
#include <sstd/sstd.hpp>

int main(){
    sstd::c2py<void> imgPath2mat_rRGB("./tmpDir", "pyFunctions", "imgPath2mat_rRGB", "void, ret mat_r<uint8>*, ret mat_r<uint8>*, ret mat_r<uint8>*, const char*");
    sstd::mat_r<uint8> imgR, imgG, imgB;
    imgPath2mat_rRGB(&imgR, &imgG, &imgB, "./sample.png");

    for(uint p=0; p<imgG.rows(); p++){
        for(uint q=0; q<imgG.cols(); q++){
            imgG(p, q) = sstd::round2even(0.5*((double)imgG(p, q)));
        }
    }
    
    sstd::c2py<void> mat_rRGB2img("./tmpDir", "pyFunctions", "mat_rRGB2img", "void, const char*, mat_r<uint8>*, mat_r<uint8>*, mat_r<uint8>*");
    mat_rRGB2img("./sample_reCombined.png", &imgR, &imgG, &imgB);

    return 0;
}
```
- <u>**Execution result**</u>  
![sample.png](../contents/c2py/sample.png)
![markerRight.png](../contents/c2py/markerRight.png)
![sample_reCombined.png](../contents/c2py/sample_reCombined.png)  
Input image (sample.png)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
Output image (sample_reCombined.png)


## Implementation
- Source: [sstd/src/c2py.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/c2py.cpp)
- Header: [sstd/src/c2py.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/c2py.hpp)
- Python: [sstd/src/c2py.py](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/c2py.py) 
- Test: [test/c2py.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/c2py.hpp)
