# bmat (binary-matrix)
## Abstract
`bmat` is a binary matrix calculation container.  
`bmat` はバイナリ行列計算コンテナです．

## Header file
```cpp
namespace sstd{
    class bmat;
    
    void copy(class sstd::bmat& lhs, class sstd::bmat& rhs);
    void move(class sstd::bmat& lhs, class sstd::bmat& rhs);

    void               eye(class sstd::bmat& bMat);
    void              ones(class sstd::bmat& bMat);
    void             zeros(class sstd::bmat& bMat);
    class sstd::bmat   eye(const uint& row, const uint& col); // このあたり，戻り値で関数はオーバーロードできないので，他の型についても実装すると，衝突する危険がある．(書き直し．
    class sstd::bmat  ones(const uint& row, const uint& col);
    class sstd::bmat zeros(const uint& row, const uint& col);
    class sstd::bmat   eye(const uint& size);
    class sstd::bmat  ones(const uint& size);
    class sstd::bmat zeros(const uint& size);

    class sstd::bmat LxShiftMat(uint size, uint xShift);                     // square matrix [size x size]
    class sstd::bmat RxShiftMat(uint size, uint xShift);                     // square matrix [size x size]

    class sstd::bmat       Tr(class sstd::bmat& rhs);                        // lhs = Transpose(rhs)
    void            Tr_myself(class sstd::bmat& rhs);                        // Transpose(rhs)

    class sstd::bmat      add(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs + rhs (XOR)
    class sstd::bmat      mul(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs * rhs
    class sstd::bmat      pow(class sstd::bmat  base, uint64 exponent);      // base^{exponent}
    void           add_myself(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs += rhs (XOR)
    void           mul_myself(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs *= rhs
    void           pow_myself(class sstd::bmat& base, uint64 exponent);      // lhs ^= exponent

    class sstd::bmat     and_(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs & rhs (AND)
    class sstd::bmat      or_(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs | rhs (OR)
    class sstd::bmat     not_(class sstd::bmat& rhs);                        // ~rhs (NOT)
    class sstd::bmat     xor_(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs + rhs (XOR)
    void           and_myself(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs & rhs (AND)
    void            or_myself(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs | rhs (OR)

    bool                   eq(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs == rhs
    bool                   ne(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs != rhs

    class sstd::bmat  REShift(class sstd::bmat& rhs, uint ShiftNum);         // RightExpansionShift // 行列拡大右シフト
    class sstd::bmat  DEShift(class sstd::bmat& rhs, uint ShiftNum);         // DownExpansionShift  // 行列拡大下シフト
    class sstd::bmat horzcat2(class sstd::bmat& lhs, class sstd::bmat& rhs); // lhs << rhs
    class sstd::bmat vertcat2(class sstd::bmat&  us, class sstd::bmat&  ds); // us && ds            // upside, downside.
};

class sstd::bmat{
private:
    uint rowNum;    // 行数
    uint colNum;    // 列数
    sstd::mat_c<uint64> binMat8x8;    // 8x8 の BinMartix 行列の集合
    
public:
    bmat();
    bmat(const uint& row, const uint& col);
    bmat(class bmat&  rhs);
    bmat(class bmat&& rhs);
    ~bmat(){}
    
    // inline sstd::mat_c<uint64> bMat8x8(){ return binMat8x8; } // Do not do this to avoid object copy
    inline const sstd::mat_c<uint64>& bMat8x8_R() const { return binMat8x8; }
    inline const uint rows() const;
    inline const uint cols() const;

    // RW: read and write
    inline sstd::mat_c<uint64>& bMat8x8_RW();
    inline uint& rows_RW();
    inline uint& cols_RW();

    class bmat& operator= (const class bmat& rhs); // called by "lhs = sstd::add(A, B);".
    class bmat  operator+ (const class bmat& rhs); // called by "lhs + rhs;". // XOR
    class bmat  operator* (const class bmat& rhs); // called by "lhs * rhs;". // mul
    class bmat  operator^ (const uint64& rhs);     // called by "lhs ^ rhs;". // pow (not XOR)

    class bmat  operator& (const class bmat& rhs); // called by "lhs & rhs;". // AND
    class bmat  operator| (const class bmat& rhs); // called by "lhs | rhs;". //  OR
    class bmat  operator~ ()                       // called by "~rhs;".      // NOT

    class bmat& operator+=(const class bmat& rhs); // called by "lhs += rhs;".
    class bmat& operator*=(const class bmat& rhs); // called by "lhs *= rhs;".
    class bmat& operator^=(const uint64& rhs);     // called by "lhs ^= rhs;".
    class bmat& operator&=(const class bmat& rhs); // called by "lhs &= rhs;".
    class bmat& operator|=(const class bmat& rhs); // called by "lhs |= rhs;".

    bool        operator==(const class bmat& rhs); // called by "sstd::bmat bMatA, bMatB; if(bMatA == bMatB){printf("same\n");}else{printf("different\n");}".
    bool        operator!=(const class bmat& rhs); // called by "sstd::bmat bMatA, bMatB; if(bMatA == bMatB){printf("same\n");}else{printf("different\n");}".

    class bmat  operator<<(const class bmat& rhs); // called by "sstd::bmat bMatA, bMatB, bMatC; bMatC = bMatA << bMatB;". // Horizontal connection of matrix.
    class bmat  operator&&(const class bmat&  ds); // called by "sstd::bmat bMatA, bMatB, bMatC; bMatC = bMatA && bMatB;". // Vertical connection of matrix.

    class SwapByOneIndex  operator[](const uint& p); // col-major order // called by "sstd::bmat bMat; bool buf = bMat[0]; bool bMat[0] = buf;".
    class SwapByOneIndex  operator[](const  int& p); // col-major order // called by "sstd::bmat bMat; bool buf = bMat[0]; bool bMat[0] = buf;".

    class SwapByTwoIndex  operator()(const uint& p, const uint& q); // called by "sstd::bmat bMat; bool buf = bMat(0, 0); bool bMat(0, 0) = buf;".
    class SwapByTwoIndex  operator()(const  int& p, const uint& q); // called by "sstd::bmat bMat; bool buf = bMat(0, 0); bool bMat(0, 0) = buf;".
    class SwapByTwoIndex  operator()(const uint& p, const  int& q); // called by "sstd::bmat bMat; bool buf = bMat(0, 0); bool bMat(0, 0) = buf;".
    class SwapByTwoIndex  operator()(const  int& p, const  int& q); // called by "sstd::bmat bMat; bool buf = bMat(0, 0); bool bMat(0, 0) = buf;".
};
```

## Usage
- <u>**Execution result**</u>
```cpp
#mdEx: cpp example (in)
#include <sstd/sstd.hpp>

bool isFullPeriod_LRL(std::vector<uint64>& divs, uint N, uint a, uint b, uint c){
    sstd::bmat I  = sstd::eye(N, N);
    sstd::bmat La = sstd::LxShiftMat(N, a);
    sstd::bmat Rb = sstd::RxShiftMat(N, b);
    sstd::bmat Lc = sstd::LxShiftMat(N, c);
    sstd::bmat T = (I + La)*(I + Rb)*(I + Lc);
//  sstd::printn(T);
    
    for(uint i=0; i<divs.size()-1; i++){
        sstd::bmat Tp = T^(divs[i]); // XORSHIFT
        if(Tp==I){ return false; }
    }
    sstd::bmat Tp = T^(divs[divs.size()-1]); // XORSHIFT
    if(Tp==I){ return true;
    }  else  { return false; }
}
void T_LRL(std::vector<uint64>& divs, uint N){
    uint num=0;
    printf("  a,  b,  c\n");
    for(uint a=0; a<N; a++){
        for(uint b=0; b<N; b++){
            for(uint c=0; c<N; c++){
                if(a<c && isFullPeriod_LRL(divs, N, a, b, c)){
                    printf("|%2u, %2u, %2u", a, b, c);
                    num++;
                    if(num%9==0){ printf("|\n"); }
                }
            }
        }
    }
}
int main(){
    printf("■ measureTime_start---------------\n\n"); time_m timem; sstd::measureTime_start(timem);

    // calculate divisors of 2^32-1.
//  std::vector<uint64> divs32 = sstd::divisor(4294967296-1); // Below line returns the same result of this line, but took a little time to run every time and takes a little heavy memory (about 2 GByte).
//  std::vector<uint64> divs32 = {1, 3, 5, 15, 17, 51, 85, 255, 257, 771, 1285, 3855, 4369, 13107, 21845, 65535, 65537, 196611, 327685, 983055, 1114129, 3342387, 5570645, 16711935, 16843009, 50529027, 84215045, 252645135, 286331153, 858993459, 1431655765, 4294967295};
    std::vector<uint64> divs32 = {1ull*5ull*17ull*257ull*65537ull,
                                  3ull*1ull*17ull*257ull*65537ull,
                                  3ull*5ull* 1ull*257ull*65537ull,
                                  3ull*5ull*17ull*  1ull*65537ull,
                                  3ull*5ull*17ull*257ull*    1ull,
                                  3ull*5ull*17ull*257ull*65537ull};
    
    printf("□ calculate LRL 32bits\n");
    T_LRL(divs32, 32); printf("\n");

    printf("\n■ measureTime_stop----------------\n"); sstd::measureTime_stop_print(timem);
    return 0;
}
```
- <u>**Execution result**</u>
```
#mdEx: cpp example (out)
```

## Implementation
- Source: [sstd/src/matrixContainer_binary/bmat.cpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/matrixContainer_binary/bmat.cpp)
- Header: [sstd/src/matrixContainer_binary/bmat.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/sstd/src/matrixContainer_binary/bmat.hpp)
- Test: [test/bmat.hpp](https://github.com/admiswalker/SubStandardLibrary-SSTD-/blob/master/test/bmat.hpp)
  (Not implemented yet)

