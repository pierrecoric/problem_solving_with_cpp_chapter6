/*
5. Write a program that gives and takes advice on program writing. The pro-
gram starts by writing a piece of advice to the screen and asking the user to
type in a different piece of advice. The program then ends. The next person
to run the program receives the advice given by the person who last ran
the program. The advice is kept in a file, and the contents of the file change
after each run of the program. You can use your editor to enter the initial
piece of advice in the file so that the first person who runs the program
receives some advice. Allow the user to type in advice of any length so that
it can be any number of lines long. The user is told to end his or her advice
by pressing the Return key two times. Your program can then test to see
that it has reached the end of the input by checking to see when it reads
two consecutive occurrences of the character '\n'.
*/

#include <iostream>
#include <fstream>
using namespace std;

void writeToFile(ofstream& output);
void outputFile(ifstream& input);

int main() {
    //Read
    cout << "The message of the previous user:" << endl;
    ifstream adviceRead;
    adviceRead.open("advice.txt");
    outputFile(adviceRead);
    adviceRead.close();
    //Write
    cout << endl << "Your message (press enter twice to exit):" << endl;
    ofstream adviceWrite;
    adviceWrite.open("advice.txt");
    writeToFile(adviceWrite);
    adviceWrite.close();

    cout << endl << endl << "End of program." << endl;

    return 0;
}

void writeToFile(ofstream& output) {
    char c;
    bool newLine(false);
    //Listen for input.
    while(true) {
        cin.get(c);
        //If two new lines are consecutive, stop the input.
        if(newLine && c == '\n') {
            break;
        }
        //Check for new line
        if(c == '\n') {
            newLine = true;
        } else newLine = false;

        //Put the caracter in the output file.
        output.put(c);
    }
}

void outputFile(ifstream& input) {
    char c;
    while(input.get(c)) {
        cout << c;
    }
}