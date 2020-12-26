#include <sstd/sstd.hpp>

int main(){
    std::vector<std::string> v          = {"1","2","3","4","5"};
    std::vector<std::string> v_sliced01 = v && sstd::slice_mv(1);
    std::vector<std::string> v_sliced02 = v && sstd::slice_mv(-1);
    
    sstd::printn(v);
    sstd::printn(v_sliced01);
    sstd::printn(v_sliced02);
}
