# unique_void_ptr
## Abstract

`unique_void_ptr` is a void* version of the `std::unique_ptr<T>` provided by SSTD, and is a unique SSTD implementation.
Note that the type that can be passed as a pointer is limited to the type provided by `unique_void_ptr` as a constructor.

`unique_void_ptr` は STL が提供する `std::unique_ptr<T>` の void* 版実装で，sstd の独自実装です．
注意点として，ポインタとして渡せる型は，`unique_void_ptr` がコンストラクタとして提供する型に制限されます．

## Header file
```cpp
namespace sstd{
    
    class unique_void_ptr{
    private:
        uint typeNumber;
        void* pData;
    public:
        unique_void_ptr();                                           // default constructor
        unique_void_ptr(const class unique_void_ptr&  rhs) = delete; // copy constructor (Note: disabled)
        unique_void_ptr(      class unique_void_ptr&& rhs);          // move constructor
        
        unique_void_ptr(       bool* ptr);
        unique_void_ptr(       char* ptr);
        unique_void_ptr(      int8 * ptr);
        unique_void_ptr(      int16* ptr);
        unique_void_ptr(      int32* ptr);
        unique_void_ptr(      int64* ptr);
        unique_void_ptr(     uint8 * ptr);
        unique_void_ptr(     uint16* ptr);
        unique_void_ptr(     uint32* ptr);
        unique_void_ptr(     uint64* ptr);
        unique_void_ptr(      float* ptr);
        unique_void_ptr(     double* ptr);
        unique_void_ptr(std::string* ptr);
        
        unique_void_ptr(std::vector<       bool>* ptr);
        unique_void_ptr(std::vector<       char>* ptr);
        unique_void_ptr(std::vector<      int8 >* ptr);
        unique_void_ptr(std::vector<      int16>* ptr);
        unique_void_ptr(std::vector<      int32>* ptr);
        unique_void_ptr(std::vector<      int64>* ptr);
        unique_void_ptr(std::vector<     uint8 >* ptr);
        unique_void_ptr(std::vector<     uint16>* ptr);
        unique_void_ptr(std::vector<     uint32>* ptr);
        unique_void_ptr(std::vector<     uint64>* ptr);
        unique_void_ptr(std::vector<      float>* ptr);
        unique_void_ptr(std::vector<     double>* ptr);
        unique_void_ptr(std::vector<std::string>* ptr);
        
        ~unique_void_ptr();

        uint typeNum();
        void* ptr();
    };
}
```

## Description
| Class name | Member function name | Description |
| ---------- | ------------- | ----------- |
| unique_void_ptr() | unique_void_ptr() | initializes the typeNumber and pData according to the called constructor.<br>呼び出されたコンストラクタに合わせて typeNumber と pData を初期化します． |
| unique_void_ptr() | ~unique_void_ptr() | releases the memory on pData. <br>pData に保存されているメモリを解放します． |
| unique_void_ptr() | ptr() | returns the pointer to the object.<br>オブジェクトへのポインタを返します． |
| unique_void_ptr() | typeNum() | returns the type number defined on ["src/definitions/typeNum.hpp"](../definitions/typeNum.md).<br>["src/definitions/typeNum.hpp"](../definitions/typeNum.md) で定義された型の番号を返却します． |

## Usage

### Construction and destruction

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    {
        sstd::unique_void_ptr void_ptr = sstd::unique_void_ptr(new std::string("abc")); // allocates the memory

        std::string* ptr = (std::string*)void_ptr.ptr(); // gets pointer to the allocated std::string on the avobe line.
        sstd::printn(*ptr);

        sstd::printn(void_ptr.typeNum()); // returns the type number defined on "src/definitions/typeNum.hpp"

        // releasing the memory on void_ptr
    }
    // memory on void_ptr is release
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### move

The `sstd::unique_void_ptr` object can not copy itself in order not to increase the owner of the memory, but can move the object and its owner.
This example shows that how to move the `sstd::unique_void_ptr` object.

`sstd::unique_void_ptr` オブジェクトは，メモリーの所有権を増加させないために，自分自身のコピーを作成できません．しかし，オブジェクトとオブジェクトの所有権はムーブできます．
このサンプルでは，`sstd::unique_void_ptr` オブジェクトのムーブについて説明します．

- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    printf("Init unique_void_ptr:\n");
    sstd::unique_void_ptr void_ptr_01 = sstd::unique_void_ptr(new std::string("abc")); // allocates the memory
    sstd::printn(void_ptr_01.typeNum());
    sstd::printn(void_ptr_01.ptr());
    printf("\n");

    printf("Move the object and its owner:\n");
    sstd::unique_void_ptr void_ptr_02 = std::move(void_ptr_01); // move the object and its owner
    sstd::printn(void_ptr_01.typeNum());
    sstd::printn(void_ptr_01.ptr());
    sstd::printn(void_ptr_02.typeNum());
    sstd::printn(void_ptr_02.ptr());
    printf("\n");
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
Note: typeNum is defined at [../definitions/typeNum.hpp](../definitions/typeNum.md).

## Implementation
- Source: [sstd/src/memory/unique_void_ptr.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/unique_void_ptr.cpp)
- Header: [sstd/src/memory/unique_void_ptr.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/memory/unique_void_ptr.hpp)
- Test: [test/src_test/memory/unique_void_ptr.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/src_test/memory/unique_void_ptr.cpp)

