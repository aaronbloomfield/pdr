/*
University of Virginia
CS 2150 In-Lab 8
Spring 2018
Test file for mergeSort
*/

#include <iostream>
using namespace std;

extern "C" void mergeSort(int * arr, int left, int right);
extern "C" void merge(int * arr, int left, int mid, int right);

int main() {

    int size;
    // prompt for array size
    cout << "Enter the array size: ";
    cin >> size;
    int * arr = new int[size];

    // read in array values
    for(int i = 0; i < size; i++) {
        cout << "Enter value " << i << ": ";
        cin >> arr[i];
    }

    // print unsorted array
    cout << "Unsorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, size-1);

    // print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

}
