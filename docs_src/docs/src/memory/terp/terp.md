# terp
## Abstract
The SSTD in**<u>terp</u>**reter type object class.
`sstd::terp` class provides the interface to treat built-in data types as a interpreter like object.

The SSTD インタープリタ型オブジェクトクラス．
`sstd::terp` クラスは，組み込み型のデータタイプをインタープリタオブジェクトのように取り扱うインターフェースを提供します．

## Header file
```cpp
//-----------------------------------------------------------------------------------------------------------------------------------------------
// forward declaration

namespace sstd::terp{
    // hash
    var hash(uint allocate_size);
    var hash();
    
    // list
    var list(uint allocate_size);
    var list();
    
    // type check
    bool isHash (const sstd::terp::var& rhs);
    bool isList (const sstd::terp::var& rhs);
    bool isNull (const sstd::terp::var& rhs);
    bool isValue(const sstd::terp::var& rhs);

    // copy
    bool copy     (sstd::terp::var& lhs, const sstd::terp::var& rhs);
    bool eRef_copy(sstd::terp::var& lhs, const sstd::terp::var& rhs);
    bool deep_copy(sstd::terp::var& lhs, const sstd::terp::var& rhs);

    // equal
    bool equal    (const sstd::terp::var& lhs, const sstd::terp::var& rhs);
    bool equal_val(const sstd::terp::var& lhs, const sstd::terp::var& rhs);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------
// iterator

class sstd::terp::iterator{
public:
    iterator();
    iterator(const _v_iterator& rhs);
    iterator(const _h_iterator& rhs);
    ~iterator();

    const _v_iterator& _v_itr_R() const;
    const _h_iterator& _h_itr_R() const;

    iterator operator+(const int rhs);
    
    template <typename T> T first_to() const;
    template <typename T> T second_to() const;
    sstd::terp::var second();
    
    const bool operator!=(const iterator& rhs) const;
    class iterator operator++();
};

//-----------------------------------------------------------------------------------------------------------------------------------------------

class sstd::terp::var{
public:
    var();
    var(const class var&   rhs);
    var(      class var&&  rhs);
    var(const class var*  pRhs);
    var(const bool         rhs);
    var(const char         rhs);
    var(const  int8        rhs);
    var(const  int16       rhs);
    var(const  int32       rhs);
    var(const  int64       rhs);
    var(const uint8        rhs);
    var(const uint16       rhs);
    var(const uint32       rhs);
    var(const uint64       rhs);
    var(const  float       rhs);
    var(const double       rhs);
    var(const char*        rhs);
    var(const std::string& rhs);
    ~var();

    //---
    // internal
    
    uint type() const;
    bool is_reference() const;
    
    //---
    // common
    
    bool copy(const class sstd::terp::var&  rhs);
    void move(      class sstd::terp::var&& rhs);
    
    var& operator=(const sstd::terp::var&  rhs);
    var  operator=(      sstd::terp::var&& rhs);
    
    var& operator=(const char* rhs);
    var& operator=(const  var* rhs); // for the reference of var address. // Note: sstd::terp did NOT mention the trouble with circular reference.

    bool equal    (const sstd::terp::var& rhs) const;
    bool equal_val(const sstd::terp::var& rhs) const;
    bool operator==(const sstd::terp::var& rhs);
    bool operator!=(const sstd::terp::var& rhs);

          var& operator[](const int idx);
    const var& operator[](const int idx) const;
          var& operator[](const char* pKey);
    const var& operator[](const char* pKey) const;
          var& operator[](const std::string key);
    const var& operator[](const std::string key) const;
    
    sstd::terp::iterator begin() const;
    sstd::terp::iterator end  () const;
    
    uint size() const;
    
    template <typename T> const T to() const;
    
    uint typeNum() const;
    std::string typeStr() const;
    
    //---
    // for hash type
    
    uint bucket_count();

    sstd::terp::iterator erase(const sstd::terp::iterator& rhs);
    uint erase(const char* pKey);
    
    sstd::terp::iterator find(const char* pKey) const;
    
    //---
    // for list type
    
    void pop_back();

    void push_back(const char* pRhs);
    void push_back(const sstd::terp::var& rhs);
    
    void resize(uint len);
};

//-----------------------------------------------------------------------------------------------------------------------------------------------
```

## Description

### `sstd::terp`

| Function name | Description |
| ------------- | ----------- |
| hash() | allocates memory for the hash type objects.<br>ハッシュ型用のメモリ領域を確保します． |
| list() | allocates memory for the list type objects.<br>リスト型用のメモリ領域を確保します． |
| isHash() | checks if the input argument is hash type.<br>入力引数がハッシュ型であるか確認します． |
| isList() | checks if the input argument is list type.<br>入力引数がリスト型であるか確認します． |
| isNull() | checks if the input argument is null type.<br>入力引数が Null 型であるか確認します． |
| isValue() | checks if the input argument has value.<br>入力引数が値を持つか確認します． |
| copy(lhs, rhs) | copies rhs to lhs. Internal reference structures are also copied as it is. External reference is copied by original external address.<br>rhs の値を lhs にコピーします．内部参照は構造を保ったままコピーされます．外部参照は元の外部アドレスがコピーされます． |
| eRef_copy(lhs, rhs) | copies rhs to lhs. Internal and external references are copied by address.<br>rhs の値を lhs にコピーします．内部参照および外部参照は元のオブジェクトのアドレスをコピーします． |
| deep_copy(lhs, rhs) | copies rhs to lhs. Reference is copied by actual value.<br>rhs の値を lhs にコピーします．参照は実体を持つ値としてコピーされます． |
| equal()       | checks if the value of arg value is equal to itself. In this case, both the value and the reference are checked.<br>引数の値が自分自身と等しいか確認します．このとき，値と参照の両方を確認します． |
| equal_val()   | checks if the value of arg value is equal to itself. In this case, only the values are checked. Reference structure's consistency is not checked.<br>引数の値が自分自身と等しいか確認します．このとき，値の一致のみを確認します．参照構造の一致は確認されません． |

### `sstd::terp::iterator`

| Function name | Description |
| ------------- | ----------- |
| first_to&lt;T&gt;()  | converts the data of list or hash-key to the specified type.<br>リストまたはハッシュのキーのデータを指定された型に変換します． |
| second_to&lt;T&gt;() | converts the data of hash-value to the specified type.<br>ハッシュのバリューのデータを指定された型に変換します． |
| second()       | returns the data of hash-value type.<br>ハッシュのバリューのデータを返却します． |

### `sstd::terp::var`

#### internal

| Function name | Description |
| ------------- | ----------- |
| type()         | returns the internal type number.<br>内部のタイプ番号を返却します． |
| is_reference() | returns if the value is reference or not.<br>該当の値が参照かどうかを返却します． |

#### common

| Function name | Description |
| ------------- | ----------- |
| begin()       | returns the start point of the iterator.<br>イテレータの開始位置を返却します． |
| end()         | returns the end point of the iterator.<br>イテレータの終了位置を返却します． |
| equal()       | is same with `sstd::terp::equal()`.<br>`sstd::terp::equal()` と同じ． |
| equal_val()   | is same with `sstd::terp::equal_val()`<br>`sstd::terp::equal_val()` と同じ． |
| size()        | returns the size of instance.<br> インスタンスのサイズを返却します． |
| to&lt;T&gt;() | converts the data to the specified type.<br>データを指定された型に変換します． |
| typeNum()     | returns the data type. The type definition is in [definitions/typeNum](../../definitions/typeNum.md).<br>データ型を返却します．型定義は [definitions/typeNum](../../definitions/typeNum.md) を参照すること． |
| typeStr()     | returns the data type name string. The definition is in [definitions/typeNum](../../definitions/typeNum.md).<br>データ型の名前を文字列で返却します．定義は [definitions/typeNum](../../definitions/typeNum.md) を参照すること． |

#### for hash type

| Function name | Description |
| ------------- | ----------- |
| bucket_count() | is allocated size of the hash table.<br>ハッシュテーブルのテーブルとして確保されているサイズ． |
| erase()        | erases the key-value pair at the hash table.<br>ハッシュテーブルにある key-value 要素を削除する． |
| find()         | searches the key at the hash table.<br>ハッシュテーブル中のキーを検索する． |

#### for list type

| Function name | Description |
| ------------- | ----------- |
| pop_back()  | deletes the last element of the list.<br>リストの末尾の要素を削除します． |
| push_back() | append the value to the end of the list type.<br>list 型の末尾に要素を追加します．|
| resize()    | resize the allocated size of the list.<br>リスト型に確保されている領域をリサイズします． |

## Usage

### `sstd::terp`

#### hash(), list()

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(3);
    x[0] = "a";
    x[1] = sstd::terp::list(2);
    x[1][0] = "b";
    x[1][1] = "c";
    x[2] = sstd::terp::hash();
    x[2]["key"] = "value";
    
    sstd::printn(x);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### isHash(), isList(), isNull(), isValue()

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    sstd::printn(isHash(x));
    sstd::printn(isList(x));
    sstd::printn(isNull(x));
    sstd::printn(isValue(x));
    printf("\n");
    
    x = sstd::terp::hash();
    sstd::printn(isHash(x));
    sstd::printn(isList(x));
    sstd::printn(isNull(x));
    sstd::printn(isValue(x));
    printf("\n");
    
    x = sstd::terp::list();
    sstd::printn(isHash(x));
    sstd::printn(isList(x));
    sstd::printn(isNull(x));
    sstd::printn(isValue(x));
    printf("\n");
    
    x = "str";
    sstd::printn(isHash(x));
    sstd::printn(isList(x));
    sstd::printn(isNull(x));
    sstd::printn(isValue(x));
    printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### copy()

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(2);
    x[0] = sstd::terp::list(3);
    x[0][0] = "a";
    x[0][1] = "b";
    x[0][2] = "c";
    x[1] = &x[0];
    
    sstd::terp::var y;
    sstd::terp::copy(y, x); // Reference structure is also copied. / 参照構造もコピーされます．
    
    sstd::printn(x[1].is_reference());
    sstd::printn(y[1].is_reference());
    sstd::printn(&x[0]);
    sstd::printn(x[1].p()); // x[1] references the x[0], as it defined. / 定義通り，x[1] は x[0] を参照しています．
    sstd::printn(&y[0]);
    sstd::printn(y[1].p()); // In this case, y[1] references the y[0]. The copy() function makes reference structures in y that is identical to x. / この場合，y[1] は y[0] を参照しています．copy() 関数は y 内部に x と同様の参照構造を作ります．
    sstd::printn(sstd::terp::equal(x, y));
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### eRef_copy()

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(2);
    x[0] = sstd::terp::list(3);
    x[0][0] = "a";
    x[0][1] = "b";
    x[0][2] = "c";
    x[1] = &x[0];
    
    sstd::terp::var y;
    sstd::terp::eRef_copy(y, x); // Reference structure is also copied. / 参照構造もコピーされます．
    
    sstd::printn(x[1].is_reference());
    sstd::printn(y[1].is_reference());
    sstd::printn(&x[0]);
    sstd::printn(x[1].p());
    sstd::printn(y[1].p()); // In this case, y[1] references the x[0]. The eRef_copy() function copies the address of the reference in the x object. / この場合，y[1] は x[0] を参照します．eRef_copy() 関数はアドレスをコピーして x オプジェクトの参照先を参照します．
    sstd::printn(sstd::terp::equal(x, y));
    sstd::printn(sstd::terp::equal_val(x, y));
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### deep_copy()

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(2);
    x[0] = sstd::terp::list(3);
    x[0][0] = "a";
    x[0][1] = "b";
    x[0][2] = "c";
    x[1] = &x[0];
    
    sstd::terp::var y;
    sstd::terp::deep_copy(y, x); // Reference structure is also copied. / 参照構造もコピーされます．

    sstd::printn(x[1].is_reference());
    sstd::printn(y[1].is_reference()); // In this case, y[1] is NOT a reference, but an actual object. / この場合，y[1] は参照ではなく，実際のオブジェクトです．
    sstd::printn(sstd::terp::equal(x, y));
    sstd::printn(sstd::terp::equal_val(x, y));
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### equal(), equal_val()

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(2);
    x[0] = sstd::terp::list(3);
    x[0][0] = "a";
    x[0][1] = "b";
    x[0][2] = "c";
    x[1] = &x[0];
    
    sstd::terp::var y; // has same value and reference structure with x. / x と同様の値を参照構造を持つ．
    y = sstd::terp::list(2);
    y[0] = sstd::terp::list(3);
    y[0][0] = "a";
    y[0][1] = "b";
    y[0][2] = "c";
    y[1] = &y[0];
    
    sstd::terp::var z; // has same value structure with x. But did not have same reference structure with x. / x と同様の値の構造を持つ．しかし，x と同一の参照構造は持たない．
    z = sstd::terp::list(2);
    z[0] = sstd::terp::list(3);
    z[0][0] = "a";
    z[0][1] = "b";
    z[0][2] = "c";
    z[1] = sstd::terp::list(3);
    z[1][0] = "a";
    z[1][1] = "b";
    z[1][2] = "c";
    
    sstd::printn(x[1].is_reference());
    sstd::printn(y[1].is_reference());
    sstd::printn(z[1].is_reference());
    printf("\n");
    
    sstd::printn(sstd::terp::equal    (x, y));
    sstd::printn(sstd::terp::equal    (x, z));
    sstd::printn(sstd::terp::equal_val(x, y));
    sstd::printn(sstd::terp::equal_val(x, z));
    printf("\n");
    
    sstd::printn(x==y); // Operator== is same with sstd::terp::equal(). / == 演算子は sstd::terp::equal() と同一．
    sstd::printn(x==z); // Operator== is same with sstd::terp::equal(). / == 演算子は sstd::terp::equal() と同一．
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### `sstd::terp::iterator`

#### second()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::hash();
    x["k1"] = sstd::terp::list(3);
    x["k1"][0] = "v1";
    x["k1"][1] = "v2";
    x["k1"][2] = "v3";

    auto itr=x.begin();
    sstd::printn(itr.second());
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### `sstd::terp::var`

#### [common]: begin(), end()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var xl;
    xl = sstd::terp::list(3);
    xl[0] = "a";
    xl[1] = "b";
    xl[2] = "c";
    
    for(uint i=0; i<xl.size(); ++i){
        printf("%s ", xl[i].to<std::string>().c_str());
    }
    printf("\n");
    
    for(auto itr=xl.begin(); itr!=xl.end(); ++itr){
        printf("%s ", itr.first_to<std::string>().c_str());
    }
    printf("\n");
    
    sstd::terp::var xh;
    xh = sstd::terp::hash();
    xh["k1"] = "v1";
    xh["k2"] = "v2";
    xh["k3"] = "v3";
    for(auto itr=xh.begin(); itr!=xh.end(); ++itr){
        printf("%s: %s, ", itr.first_to<std::string>().c_str(), itr.second_to<std::string>().c_str());
    }
    printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [common]: equal(), equal_val()


- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(2);
    x[0] = sstd::terp::list(3);
    x[0][0] = "a";
    x[0][1] = "b";
    x[0][2] = "c";
    x[1] = &x[0];
    
    sstd::terp::var y; // has same value and reference structure with x. / x と同様の値を参照構造を持つ．
    y = sstd::terp::list(2);
    y[0] = sstd::terp::list(3);
    y[0][0] = "a";
    y[0][1] = "b";
    y[0][2] = "c";
    y[1] = &y[0];
    
    sstd::terp::var z; // has same value structure with x. But did not have same reference structure with x. / x と同様の値の構造を持つ．しかし，x と同一の参照構造は持たない．
    z = sstd::terp::list(2);
    z[0] = sstd::terp::list(3);
    z[0][0] = "a";
    z[0][1] = "b";
    z[0][2] = "c";
    z[1] = sstd::terp::list(3);
    z[1][0] = "a";
    z[1][1] = "b";
    z[1][2] = "c";
    
    sstd::printn(x[1].is_reference());
    sstd::printn(y[1].is_reference());
    sstd::printn(z[1].is_reference());
    printf("\n");
    
    sstd::printn(x.equal    (y));
    sstd::printn(x.equal    (z));
    sstd::printn(x.equal_val(y));
    sstd::printn(x.equal_val(z));
    printf("\n");
    
    sstd::printn(x==y); // Operator== is same with sstd::terp::equal(). / == 演算子は sstd::terp::equal() と同一．
    sstd::printn(x==z); // Operator== is same with sstd::terp::equal(). / == 演算子は sstd::terp::equal() と同一．
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [common]: size()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list();
    x.push_back("a");
    x.push_back(sstd::terp::hash());
    x[x.size()-1]["k1"] = "v1";
    x[x.size()-1]["k2"] = "v2";
    
    sstd::printn(x.size());
    sstd::printn(x[x.size()-1].size());
    
    sstd::printn(x);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [common]: to&lt;T&gt;()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = "123";

    std::string xs = x.to<std::string>();
    sstd::printn(xs);
    
    int xi = x.to<int>();
    sstd::printn(xi);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [common]: typeNum(), typeStr()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    sstd::printn(x.typeNum());
    sstd::printn(x.typeStr());
    sstd::printn(sstd::typeNum2str(x.typeNum()));
    printf("\n");
    
    sstd::terp::var xl;
    xl = sstd::terp::list();
    sstd::printn(xl.typeNum());
    sstd::printn(xl.typeStr());
    sstd::printn(sstd::typeNum2str(xl.typeNum()));
    printf("\n");
    
    sstd::terp::var xh;
    xh = sstd::terp::hash();
    sstd::printn(xh.typeNum());
    sstd::printn(xh.typeStr());
    sstd::printn(sstd::typeNum2str(xh.typeNum()));
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [for hash type]: bucket_count()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::hash();
    x["k1"] = "v1";
    x["k2"] = "v2";
    x["k3"] = "v3";
    
    sstd::printn(x);
    sstd::printn(x.size());
    sstd::printn(x.bucket_count());
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [for hash type]: erase()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::hash();
    x["k1"] = "v1";
    x["k2"] = "v2";
    x["k3"] = "v3";
    sstd::printn(x);
    sstd::printn(x.size());
    
    x.erase("k1");
    x.erase("k3");
    sstd::printn(x);
    sstd::printn(x.size());
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [for hash type]: find()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::hash();
    x["k1"] = "v1";
    x["k2"] = "v2";
    x["k3"] = "v3";
    
    auto itr1 = x.find("k1");
    sstd::printn(itr1!=x.end());
    
    auto itr2 = x.find("not existing key");
    sstd::printn(itr2!=x.end());
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [for list type]: pop_back()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(3);
    x[0] = "a";
    x[1] = "b";
    x[2] = "c";
    
    sstd::printn(x);
    x.pop_back();
    sstd::printn(x);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [for list type]: push_back()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list();
    x.push_back("a");
    x.push_back("b");
    x.push_back("c");
    
    sstd::printn(x);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### [for list type]: resize()
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(3);
    x[0] = "a";
    x[1] = "b";
    x[2] = "c";
    
    sstd::printn(x);
    sstd::printn(x.size());
    x.resize(1);
    sstd::printn(x);
    sstd::printn(x.size());
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### `sstd::terp::var`'s references

`sstd::terp::var` allows references between the same variable types as `sstd::terp::var`.
Internal reference means a self-contained reference within the same variable.
External reference means a reference to another variable.

`sstd::terp::var` は同じ `sstd::terp::var` 型間で参照を張ることができます．
内部参照は同じ変数内で自己完結する参照を意味します．外部参照は別の変数への参照を意味します．

#### Internal reference

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var x;
    x = sstd::terp::list(2);
    x[0] = sstd::terp::list(3);
    x[0][0] = "a";
    x[0][1] = "b";
    x[0][2] = "c";
    x[1] = &x[0]; // This is an internal reference. x references one of the internal address of variable x. / これは内部参照です．x は変数 x の内部アドレスの 1 つを参照します．
    
    sstd::printn(&x[0]);
    sstd::printn(x[1].p());
    sstd::printn(x[1].is_reference());
    printf("\n");
    
    sstd::printn(x);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

#### External reference

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::terp::var y;
    
    {
        sstd::terp::var x;
        x = sstd::terp::list(3);
        x[0] = "a";
        x[1] = "b";
        x[2] = "c";
        
        sstd::terp::var y = &x; // This is an external reference. y references another variable x. / これは外部参照です．y は別の変数 x を参照します．
        
        sstd::printn(&x);
        sstd::printn(y.p());
        sstd::printn(y.is_reference());
        printf("\n");
        
        sstd::printn(x);
        sstd::printn(y);
        printf("\n");
        
    } // x deleted by the out of scope. / x がスコープを超えて削除される．
    
    sstd::printn(y.p()); // NULL filled if the referencing address freed. / 参照先のアドレスが解放された場合 NULL 埋めされます．
    sstd::printn(y);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/memory/terp/terp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/terp/terp.cpp)
- Header: [sstd/src/memory/terp/terp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/terp/terp.hpp)
- Test: [test/memory/terp/terp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/memory/terp/terp.cpp)

