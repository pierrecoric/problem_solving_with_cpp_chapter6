/*
29.	Define a function called copy_char that takes one argument that is an
input stream. When called, copy_char will read one character of input
from the input stream given as its argument and will write that character
to the screen. You should be able to call your function using either cin
or an input-file stream as the argument to your function copy_char. (If
the argument is an input-file stream, then the stream is connected to a
file before the function is called, so copy_char will not open or close any
files.) For example, the first of the following two calls to copy_char will
copy a character from the file stuff.dat to the screen, and the second
will copy a character from the keyboard to the screen:
ifstream fin;
fin.open("stuff.dat");
copy_char(fin);
copy_char(cin);
*/

#include <iostream>
#include <fstream>
using namespace std;

void copy_char(istream& input);

int main () {
    ifstream fin;
    fin.open("data.dat");
    cout << "now with a file:" << endl;
    copy_char(fin);
    cout << endl << "now with the keyboard" << endl;
    copy_char(cin);
    cout << endl << "end of demo." << endl;
    fin.close();
    return 0;
}

void copy_char(istream& input) {
    char c;
    input.get(c);
    cout << c;
}