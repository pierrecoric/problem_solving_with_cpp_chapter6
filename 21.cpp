/*
20. Write the definition for a void function called to_screen. The function
to_screen has one formal parameter called file_stream, which is of type
ifstream. The precondition and postcondition for the function are as
follows:

//Precondition: The stream file_stream has been connected
//to a file with a call to the member function open. The
//file contains a list of integers (and nothing else).
//Postcondition: The numbers in the file connected to
//file_stream have been written to the screen one per line.
//(This function does not close the file.)
*/

#include <iostream>
#include <fstream>

void to_screen(std::ifstream& file_stream);

int main() {
    using namespace std;
    ifstream f;
    f.open("data.dat");
    to_screen(f);
    f.close();
    return 0;
}

void to_screen(std::ifstream& file_stream) {
    using namespace std;
    int next;
    while(file_stream >> next) {
        cout << next << endl;
    }
}