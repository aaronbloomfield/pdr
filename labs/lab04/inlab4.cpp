
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
void tableDump(string (*arr)[5], string (*arr1)[4]);

int main(){

	// Replace the empty strings below with
	// the values you found while experimenting.

	string nonPointers[6][5] = {
		{"int", "" /*size*/, "" /*max value*/, "" /*zero as stored in hex*/,"" /*one as stored in hex*/},
		{"unsigned int", "" /*size*/, "" /*max value*/, "" /*zero as stored in hex*/, "" /*one as stored in hex*/},
		{"float", "" /*size*/, "" /*max value*/, "" /*zero as stored in hex*/, "" /*one as stored in hex*/},
		{"double", "" /*size*/, "" /*max value*/, "" /*zero as stored in hex*/, "" /*one as stored in hex*/},
		{"char", "" /*size*/, "" /*max value*/, "" /*zero as stored in hex*/, "" /*one as stored in hex*/},
		{"bool", "" /*size*/, "" /*max value*/, "" /*zero as stored in hex*/, "" /*one as stored in hex*/},

	};

	string pointers[3][4] = {
		{"int*", "" /*size*/, "" /*max value*/, "" /*NULL as stored in hex*/},
		{"char*", "" /*size*/, "" /*max value*/, "" /*NULL as stored in hex*/},
		{"double*", "" /*size*/, "" /*max value*/, "" /*NULL as stored in hex*/},
	};

	tableDump(nonPointers, pointers);
	return 0;
}

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 4; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
	}
}
