# mat_r (Row-major)
## Abstract
`mat_r` is a row-major matrix container.  
`mat_r` は行優先の行列コンテナです.

## Header file
```cpp
namespace sstd{
    template <typename T> class mat_r;
    template <typename T> void copy(sstd::mat_r<T>& lhs, const sstd::mat_r<T>& rhs);
    template <typename T> void move(sstd::mat_r<T>& lhs,       sstd::mat_r<T>& rhs);
    template <typename T> void swap(sstd::mat_r<T>& lhs,       sstd::mat_r<T>& rhs);
    
    template <typename T> void   eye(sstd::mat_r<T>& rhs);
    template <typename T> void  ones(sstd::mat_r<T>& rhs);
    template <typename T> void zeros(sstd::mat_r<T>& Mat);
    template <typename T> sstd::mat_r<T> Tr       (const sstd::mat_r<T>& rhs); // lhs = Transpose(rhs)
    template <typename T> void           Tr_myself(      sstd::mat_r<T>& rhs); // Transpose(rhs)
}

template <typename T>
class sstd::mat_r{
private:
    T* _pMatT;
    uint _rows; // row size
    uint _cols; // column size
    uint _size; // number of element
    
public:
    inline mat_r();
    inline mat_r(const std::initializer_list<std::initializer_list<T>>& rhs); // called by "sstd::mat_r<T> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};".
    inline mat_r(const class mat_r&  rhs); // called by "sstd::mat_r<T> buf1(N, N); sstd::mat_r<T> buf2(buf1);"
    inline mat_r(      class mat_r&& rhs); // called by "return std::move(rhs);" or "std::swap(buf1, buf2)".
    inline mat_r(const uint& rowSize, const uint& colSize);
    inline ~mat_r();

    // Read only: R
    inline const uint rows() const;
    inline const uint cols() const;
    inline const uint size() const;

    // Read and Write: RW
    inline T*& pMatT_RW();
    inline uint& rows_RW();
    inline uint& cols_RW();
    inline uint& size_RW();

    class mat_r& operator=(const class mat_r& rhs); // called by "lhs = sstd::mat_r<T>(3, 3);".

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
    inline sstd::mat_r_elements<T> operator()();
    inline sstd::mat_r_elements<T>        vec();
};
```

## Usage
### Init
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m = {{1,2}, {3,4}};
    sstd::mat_r<double> m_eye(2,2); sstd::eye(m_eye);
    sstd::mat_r<double> m_ones(2,2); sstd::ones(m_ones);
    sstd::mat_r<double> m_zeros(2,2); sstd::zeros(m_zeros);
    sstd::printn(m); printf("\n");
    sstd::printn(m_eye); printf("\n");
    sstd::printn(m_ones); printf("\n");
    sstd::printn(m_zeros);
}
```
- output  
```
#mdEx: cpp example (out)
```

### Access to elements
#### As a matrix
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m(2, 2);

    uint i = 0;
    for(uint r=0; r<m.rows(); ++r){
        for(uint c=0; c<m.cols(); ++c){
            m(r, c) = i; ++i;
        }
    }
    
    sstd::printn(m);
}
```
- output  
```
#mdEx: cpp example (out)
```
#### As a vector
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m(2, 2);

    for(uint i=0; i<m.size(); ++i){
        m[i] = i;
    }
    
    sstd::printn(m);
}
```
- output  
```
#mdEx: cpp example (out)
```

### Tr (Transpose)
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m1 = {{1,2}, {3,4}};
    sstd::printn( m1 );
    sstd::printn( sstd::Tr( m1 ) ); printf("\n");
    
    sstd::mat_r<double> m2 = {{1,2}, {3,4}};
    sstd::printn( m2 );
    sstd::Tr_myself(m2);
    sstd::printn( m2 );
}
```
- output  
```
#mdEx: cpp example (out)
```

### Operator
#### matrix × scalar
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m(2, 2); for(uint i=0; i<m.size(); ++i){ m[i]=i; }
    sstd::printn( m ); printf("\n");
    sstd::printn( m * 2 );
}
```
- output  
```
#mdEx: cpp example (out)
```
#### matrix × matrix
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m1(2, 2); for(uint i=0; i<m1.size(); ++i){ m1[i]=i; }
    sstd::mat_r<double> m2(2, 2); for(uint i=0; i<m2.size(); ++i){ m2[i]=i+1; }
    sstd::printn( m1 ); printf("\n");
    sstd::printn( m2 ); printf("\n");
    sstd::printn( m1 * m2 );
}
```
- output  
```
#mdEx: cpp example (out)
```
#### matrix (as a vector) × matrix (as a vector)
- input
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

int main(){
    sstd::mat_r<double> m1(2, 2); for(uint i=0; i<m1.size(); ++i){ m1[i]=i; }
    sstd::mat_r<double> m2(2, 2); for(uint i=0; i<m2.size(); ++i){ m2[i]=i+1; }
    sstd::printn( m1 ); printf("\n");
    sstd::printn( m2 ); printf("\n");
    sstd::printn( m1() * m2() );
}
```
- output  
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/matrixContainer_rowMajor/mat_r.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/matrixContainer_rowMajor/mat_r.cpp)
- Header: [sstd/src/matrixContainer_rowMajor/mat_r.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/matrixContainer_rowMajor/mat_r.hpp)
- Test: [test/mat_r.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/mat_r.hpp)
  (Not implemented yet)

