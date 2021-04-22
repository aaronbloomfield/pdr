#include <iostream>
#include <cstring>
#include "timer.h"
using namespace std;

extern "C" int binarySearch(int * arr, int left, int right, int target);

int main(int argc, char** argv){

    // Check if silent cmd line param was passed in
    // This is used for autograding purposes but can be ignored otherwise
    bool print = true;
    if (argc > 1){
        string opt = "-s";
        print = (strcmp(opt.c_str(), argv[1]) != 0);
    }

    // prompt for array size
	int size;
    if (print)
    	cout << "Enter the array size: ";
	cin >> size;
	int * arr = new int[size];

	// read in array values
	for(int i = 0; i < size; i++) {
        if(print)
            cout << "Enter value " << i << ": ";
        cin >> arr[i];
    }

    // prompt for target
    int target;
    if(print)
        cout << "Enter target to search for: ";
    cin >> target;

    int ind = binarySearch(arr, 0, size-1, target);

    if (ind > -1)
    	cout << "\nFound " << target << " at index " << ind << endl;
    else
    	cout << "\nDid not find " << target << endl;

    // timing tests
    timer t;
    t.start();
    for(int i = 0; i < 1000; i++){
        binarySearch(arr, 0, size-1, target);
    }
    t.stop();

    cout << "Took " << t.getTime()*1000 << "ms" << endl;

    return 0;

}
