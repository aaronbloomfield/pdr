#include <iostream>
#include <string>
#include <time.h>
#include <sys/time.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;


// this is the timer class from lab 6, included here so as not to
// require multiple files to compile
class timer {
private:
    timeval startVar, stopVar;
    bool running;

public:
    timer() : running(0) {}
    ~timer() {}
    timer(timer & myTimer);
    int start();
    int stop();
    string toString();
    ostream & print(ostream &theStream);
};

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

string timer::toString() {
    ostringstream out;
    int ms, s, m, h;
    int totalmsec;
    if (running)
        out << "Timer still running\n";
    else {
        time_t sec = stopVar.tv_sec - startVar.tv_sec;
        long usec = stopVar.tv_usec - startVar.tv_usec;
        if ( usec < 0 ) {
            sec--;
            usec += 1000000;
        }
        out << (sec*1000+usec/1000);
    }
    return out.str();
}

ostream & operator<<(ostream &out, timer &t) {
    return t.print(out);
}


// this main method just counts the time taken to iterate 1 billion
// times through an idle loop

int main(int argc, char **argv) {
    // check the number of parameters
    if ( argc != 2 ) {
        cerr << "usage: " << argv[0] << " <iterations>" << endl;
        exit(1);
    }
    // convert the second parameter to a int
    int e, ret;
    ret = sscanf (argv[1], "%d", &e);
    if ( ret != 1 ) {
        cerr << "error reading input: '" << argv[1] << "'" << endl;
        exit (2);
    }
    // compute 10^e
    long n = 1;
    for ( int i = 0; i < e; i++ )
        n *= 10;
    timer t;
    t.start();
    // do something that takes some time...
    for ( long i = 0; i < n; i++ );
    t.stop();
    cout << t << endl;
}
