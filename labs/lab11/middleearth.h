#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
    int num_city_names, xsize, ysize;
    vector<float> xpos, ypos;
    vector<string> cities;
    float *distances;
    map<string, int> indices;

public:
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    ~MiddleEarth();
    void print();
    void printTable();
    float getDistance (string city1, string city2);
    vector<string> getItinerary(unsigned int length);
};

#endif
