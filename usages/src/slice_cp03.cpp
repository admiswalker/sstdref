#include <sstd/sstd.hpp>

int main(){
    std::vector<int> v        = {1,2,3,4,5};
    std::vector<int> v_sliced = v && sstd::slice(sstd::begin(),sstd::end());
    
    sstd::printn(v);
    sstd::printn(v_sliced);
}
