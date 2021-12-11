# mat_c (Col-major)
## Abstract
`mat_c` is a column-major matrix container.  
`mat_c` は列優先の行列コンテナです.

## Header file
```cpp
namespace sstd{
    template <typename T> class mat_c;
    template <typename T> void copy(sstd::mat_c<T>& lhs, const sstd::mat_c<T>& rhs);
    template <typename T> void move(sstd::mat_c<T>& lhs,       sstd::mat_c<T>& rhs);
    template <typename T> void swap(sstd::mat_c<T>& lhs,       sstd::mat_c<T>& rhs);
    
    template <typename T> void   eye(sstd::mat_c<T>& rhs);
    template <typename T> void  ones(sstd::mat_c<T>& rhs);
    template <typename T> void zeros(sstd::mat_c<T>& Mat);
    template <typename T> sstd::mat_c<T> Tr       (const sstd::mat_c<T>& rhs); // lhs = Transpose(rhs)
    template <typename T> void           Tr_myself(      sstd::mat_c<T>& rhs); // Transpose(rhs)
}

template <typename T>
class sstd::mat_c{
private:
    T* _pMatT;
    uint _rows; // row size
    uint _cols; // column size
    uint _size; // number of element
    
public:
    inline mat_c();
    inline mat_c(const std::initializer_list<std::initializer_list<T>>& rhs); // called by "sstd::mat_c<T> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};".
    inline mat_c(const class mat_c&  rhs); // called by "sstd::mat_c<T> buf1(N, N); sstd::mat_c<T> buf2(buf1);"
    inline mat_c(      class mat_c&& rhs); // called by "return std::move(rhs);" or "std::swap(buf1, buf2)".
    inline mat_c(const uint& rowSize, const uint& colSize);
    inline ~mat_c();

    // Read only: R
    inline const uint rows() const;
    inline const uint cols() const;
    inline const uint size() const;

    // Read and Write: RW
    inline T*& pMatT_RW();
    inline uint& rows_RW();
    inline uint& cols_RW();
    inline uint& size_RW();

    class mat_c& operator=(const class mat_c& rhs); // called by "lhs = sstd::mat_c<T>(3, 3);".

    inline       T& operator[](const uint i);
    inline       T& operator[](const  int i);
    inline const T& operator[](const uint i) const;
    inline const T& operator[](const  int i) const;

    inline       T& operator()(const uint p, const uint q);
    inline       T& operator()(const  int p, const uint q);
    inline       T& operator()(const uint p, const  int q);
    inline       T& operator()(const  int p, const  int q);
    inline const T& operator()(const uint p, const uint q) const;
    inline const T& operator()(const  int p, const uint q) const;
    inline const T& operator()(const uint p, const  int q) const;
    inline const T& operator()(const  int p, const  int q) const;
    
    // for element operations (elements multiplication)
    inline sstd::mat_c_elements<T> operator()();
    inline sstd::mat_c_elements<T>        vec();
};
```

## Usage
### Init
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m = {{1,2}, {3,4}};
    sstd::mat_c<double> m_eye(2,2); sstd::eye(m_eye);
    sstd::mat_c<double> m_ones(2,2); sstd::ones(m_ones);
    sstd::mat_c<double> m_zeros(2,2); sstd::zeros(m_zeros);
    sstd::printn(m); printf("\n");
    sstd::printn(m_eye); printf("\n");
    sstd::printn(m_ones); printf("\n");
    sstd::printn(m_zeros);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Access to elements
#### As a matrix
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m(2, 2);

    uint i = 0;
    for(uint c=0; c<m.cols(); ++c){
        for(uint r=0; r<m.rows(); ++r){
            m(r, c) = i; ++i;
        }
    }
    
    sstd::printn(m);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### As a vector
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m(2, 2);

    for(uint i=0; i<m.size(); ++i){
        m[i] = i;
    }
    
    sstd::printn(m);
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Tr (Transpose)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m1 = {{1,2}, {3,4}};
    sstd::printn( m1 );
    sstd::printn( sstd::Tr( m1 ) ); printf("\n");
    
    sstd::mat_c<double> m2 = {{1,2}, {3,4}};
    sstd::printn( m2 );
    sstd::Tr_myself(m2);
    sstd::printn( m2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

### Operator
#### matrix × scalar
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m(2, 2); for(uint i=0; i<m.size(); ++i){ m[i]=i; }
    sstd::printn( m ); printf("\n");
    sstd::printn( m * 2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### matrix × matrix
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m1(2, 2); for(uint i=0; i<m1.size(); ++i){ m1[i]=i; }
    sstd::mat_c<double> m2(2, 2); for(uint i=0; i<m2.size(); ++i){ m2[i]=i+1; }
    sstd::printn( m1 ); printf("\n");
    sstd::printn( m2 ); printf("\n");
    sstd::printn( m1 * m2 );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```
#### matrix (as a vector) × matrix (as a vector)
- <u>**main.cpp**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_c<double> m1(2, 2); for(uint i=0; i<m1.size(); ++i){ m1[i]=i; }
    sstd::mat_c<double> m2(2, 2); for(uint i=0; i<m2.size(); ++i){ m2[i]=i+1; }
    sstd::printn( m1 ); printf("\n");
    sstd::printn( m2 ); printf("\n");
    sstd::printn( m1() * m2() );
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/matrixContainer_rowMajor/mat_c.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/matrixContainer_rowMajor/mat_c.cpp)
- Header: [sstd/src/matrixContainer_rowMajor/mat_c.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/matrixContainer_rowMajor/mat_c.hpp)
- Test: [test/mat_c.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/mat_c.hpp)
  (Not implemented yet)

