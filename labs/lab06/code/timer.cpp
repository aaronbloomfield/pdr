// NOTE: in order to compile this system on Linux (and most Unix
// systems) you will have to include the -lrt flag to your compiler.

#include <sstream>
#include <math.h>
#include <cstring>

#include "timer.h"

timer::timer(timer & t) : running(t.running) {
    memcpy(&startVar, &(t.startVar), sizeof (timeval));
    memcpy(&stopVar,  &(t.stopVar),  sizeof (timeval));
}

int timer::start() {
    if (!running) {
        running = true;
        gettimeofday(&startVar,NULL);
        return 0;
    }
    return 1;
}

int timer::stop() {
    if (running) {
        running = 0;
        gettimeofday(&stopVar,NULL);
        return 0;
    }
    return 1;
}

ostream & timer::print(ostream & out) {
    return (out << toString());
}

double timer::getTime() {
    time_t sec = stopVar.tv_sec - startVar.tv_sec;
    long usec = stopVar.tv_usec - startVar.tv_usec;
    return sec + usec/1000000.0;
}

string timer::toString() {
    ostringstream out;
    if (running)
        out << "Timer still running\n";
    else {
        time_t sec = stopVar.tv_sec - startVar.tv_sec;
        long usec = stopVar.tv_usec - startVar.tv_usec;
        if ( usec < 0 ) {
            sec--;
            usec += 1000000;
        }
        out << sec << "."
            << ((usec<100000)?"0":"")
            << ((usec<10000)?"0":"")
            << ((usec<1000)?"0":"")
            << ((usec<100)?"0":"")
            << ((usec<10)?"0":"")
            << usec;
    }
    return out.str();
}

ostream & operator<<(ostream &out, timer &t) {
    return t.print(out);
}
