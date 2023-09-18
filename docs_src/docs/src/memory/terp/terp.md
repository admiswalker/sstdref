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
    var(const var&  rhs);
    var(const sstd::void_ptr& vp_in);
    var(      sstd::void_ptr*  p_in);
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
    
    sstd::void_ptr* p() const;
    
    //---
    // common
    
    var operator=(const char* rhs);
    var operator=(const sstd::terp::var& rhs);

    bool operator==(const sstd::terp::var& rhs);
    bool operator!=(const sstd::terp::var& rhs);

          var operator[](const int idx);
    const var operator[](const int idx) const;
          var operator[](const char* pKey);
    const var operator[](const char* pKey) const;
    
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

### `sstd::terp::iterator`

| Function name | Description |
| ------------- | ----------- |
| first_to&lt;T&gt;()  | converts the data of list or hash-key to the specified type.<br>リストまたはハッシュのキーのデータを指定された型に変換します． |
| second_to&lt;T&gt;() | converts the data of hash-value to the specified type.<br>ハッシュのバリューのデータを指定された型に変換します． |
| second()       | returns the data of hash-value type.<br>ハッシュのバリューのデータを返却します． |

### `sstd::terp::var`

#### common

| Function name | Description |
| ------------- | ----------- |
| begin()       | returns the start point of the iterator.<br>イテレータの開始位置を返却します． |
| end()         | returns the end point of the iterator.<br>イテレータの終了位置を返却します． |
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

## Implementation
- Source: [sstd/src/memory/terp/terp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/terp/terp.cpp)
- Header: [sstd/src/memory/terp/terp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/terp/terp.hpp)
- Test: [test/memory/terp/terp.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/memory/terp/terp.cpp)

