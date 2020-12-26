#include <sstd/sstd.hpp>
#include <time.h>

int main(){
    time_t unixtime_UTC; time(&unixtime_UTC); // get current unixtime
    struct tm tm_UTC = sstd::time2tm(unixtime_UTC);
    struct tm tm_Local = sstd::timeGm2tmLocal(unixtime_UTC);
    
    sstd::printn(unixtime_UTC);
    sstd::printn(tm_UTC);
    sstd::printn(tm_Local);
}
