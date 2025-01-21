/*
31.	Define a function called send_line that takes one argument that is an
output stream. When called, send_line reads one line of input from the
keyboard and outputs the line to the output stream given as its argument.
You should be able to call your function using either cout or an output-
file stream as the argument to your function send_line. (If the argument
is an output-file stream, then the stream is connected to a file before the
function is called, so send_line will not open or close any files.) For
example, the first of the following calls to send_line copies a line from
the keyboard to the file morestuf.dat, and the second copies a line from
the keyboard to the screen:
ofstream fout;
fout.open("morestuf.dat");
cout << "Enter 2 lines of input:\n";
send_line(fout);
send_line(cout);
*/

#include <iostream>
#include <fstream>
using namespace std;

void send_line(ostream& output);

int main() {
    ofstream fout;
    fout.open("morestuf.dat");
    cout << "Enter two lines of input: " << endl;
    send_line(fout);
    fout.close();
    send_line(cout);
    return 0;
}

void send_line(ostream& output) {
    char c;
    do {
        cin.get(c);
        output.put(c);
    } while (c != '\n');
}