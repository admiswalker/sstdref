#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v          = {1,2,3,4,5};
    std::vector<int> v_sliced01 = v && sstd::slice(1);
    std::vector<int> v_sliced02 = v && sstd::slice(-1);
    
    sstd::printn(v);
    sstd::printn(v_sliced01);
    sstd::printn(v_sliced02);
}
