/*
6. Write a program that reads text from one file and writes an edited version
of the same text to another file. The edited version is identical to the un-
edited version except that every string of two or more consecutive blanks
is replaced by a single blank. Thus, the text is edited to remove any extra
blank characters. Your program should define a function that is called with
the input- and output-file streams as arguments. If this is being done as a
class assignment, obtain the file names from your instructor.
*/

#include <iostream>
#include <fstream>
using namespace std;

void cleanFile(ifstream& input, ofstream &output);

int main() {
    ifstream raw;
    ofstream clean;
    raw.open("raw.txt");
    clean.open("clean.txt");
    cout << "Files open for processing." << endl;
    cleanFile(raw, clean);
    raw.close();
    clean.close();
    cout << endl << endl << "End of program" << endl;
    return 0;
}

void cleanFile(ifstream& input, ofstream &output) {
    char c;
    int counter = 0;
    bool space(false);
    //While there is content in the file to be read.
    while(input.get(c)) {
        //If no space has been encountered.
        if(!space) {
            //If a space is detected, write it and raise the space flag.
            if(c == ' ') {
                output.put(c);
                space = true;
            } else output.put(c); //Otherwise, write the caracter.
        }
        //If a space has been detected and written:
        else {
            //If another space is coming after it, no writing to the clean file.
            if(c == ' ') {
                counter ++;
                cout << "space #" << counter << " deleted." << endl;
            }
            //Otherwise lower the space flag and write the character.
            else {
                space = false;
                output.put(c);
            }
        }
    }
}
