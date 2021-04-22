// NOTE: in order to compile this system on Linux (and most Unix
// systems) you will have to include the -lrt flag to your compiler.
//
// This timer typically has 1/1000000 second (1 micro-second) accuracy
// under most Linux distributions

/*Nicholas Mohammad
  nm9ur
  timer.h
  10/19/2017
*/


#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <string>
#include <time.h>
#include <sys/time.h>

using namespace std;

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
    double getTime();
};

ostream & operator<<(ostream & theStream, timer & theTimer);

#endif
