// This program shows how C++-based file I/O works.
// It will print a file to the screen two times.

// included so we can use cout
#include <iostream>
// file I/O
#include <fstream>
// cstdlib is where exit() lives
#include <cstdlib>

using namespace std;

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    while (file.get(g)) {
        cout << g;
    }

    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    // Read the file again, and print to the screen
    while (file.get(g)) {
        cout << g;
    }

    // close the file
    file.close();
}
