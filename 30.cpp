/*
30.	Define a function called copy_line that takes one argument that is an
input stream. When called, copy_line reads one line of input from the
input stream given as its argument and writes that line to the screen.
You should be able to call your function using either cin or an input-file
stream as the argument to your function copy_line. (If the argument
is an input-file stream, then the stream is connected to a file before the
function is called, so copy_line will not open or close any files.) For
example, the first of the following two calls to copy_line will copy a line
from the file stuff.dat to the screen, and the second will copy a line
from the keyboard to the screen:
ifstream fin;
fin.open("stuff.dat");
copy_line(fin);
copy_line(cin);
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string copy_line(istream& input);

int main() {
    cout << "Test: input something un peu pour voir?" << endl;
    string test = copy_line(cin);
    cout << test << endl;
    ifstream fin;
    fin.open("data.dat");
    test = copy_line(fin);
    fin.close();
    cout << test << endl;
    cout << "End of test." << endl;
    return 0;
}

string copy_line(istream& input) {
    string s("");
    char c;
    do {
        input.get(c);
        s += c;
    } while(c != '\n');
    return s;
}