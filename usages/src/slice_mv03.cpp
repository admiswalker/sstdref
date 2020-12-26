#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> v        = {"1","2","3","4","5"};
    std::vector<std::string> v_sliced = v && sstd::slice_mv(sstd::begin(),sstd::end());
    
    sstd::printn(v);
    sstd::printn(v_sliced);
}
