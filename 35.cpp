/*
35. Write the definition for a void function called text_to_screen that has
one formal parameter called file_stream that is of type ifstream. The
precondition and postcondition for the function are as follows:
//Precondition: The stream file_stream has been connected
//to a file with a call to the member function open.
//Postcondition: The contents of the file connected to
//file_stream have been copied to the screen character by
//character, so that the screen output is the same as the
//contents of the text in the file.
//(This function does not close the file.)
*/

#include <iostream>
#include <fstream>
using namespace std;

void text_to_screen(ifstream& file_stream);

int main () {
    ifstream f;
    f.open("data.dat");
    text_to_screen(f);
    f.close();
    return 0;
}

void text_to_screen(ifstream& file_stream) {
    char c;
    file_stream.get(c);
    while(! file_stream.eof()) {
        cout << c;
        file_stream.get(c);
    }
}