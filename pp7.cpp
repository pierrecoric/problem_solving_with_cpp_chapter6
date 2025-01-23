/*
7. Write a program that merges the numbers in two files and writes all the
numbers into a third file. Your program takes input from two different
files and writes its output to a third file. Each input file contains a list of
numbers of type int in sorted order from the smallest to the largest. After
the program is run, the output file will contain all the numbers in the two
input files in one longer list in sorted order from smallest to largest. Your
program should define a function that is called with the two input-file
streams and the output-file stream as three arguments. If this is being done
as a class assignment, obtain the file names from your instructor.
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void merge(ifstream& fileA, ifstream& fileB, ofstream& output);
bool validString(string s);
int stringToInt(string s);
void putString(string s, ofstream& output);

int main() {
    ifstream fileA, fileB;
    ofstream output;
    fileA.open("numbersA.dat");
    fileB.open("numbersB.dat");
    output.open("numbersOutput.dat");
    cout << "Files open for processing." << endl;
    merge(fileA, fileB, output);
    fileA.close();
    fileB.close();
    output.close();
    cout << endl << "End of program." << endl;
    return 0;
}

void merge(ifstream& fileA, ifstream& fileB, ofstream& output) {
    char ca, cb;
    string strA, strB;
    int intA, intB;
    bool doneA(false), doneB(false);
    bool foundA(false), foundB(false);


    while(!doneA && !doneB) {

        if(!foundA) {
            if(fileA.get(ca)) {
                if(ca == ' ') {
                    foundA = true;
                } else strA += ca;
            } else doneA = true;
        }
        
        if(!foundB) {
            if(fileB.get(cb)) {
                if(cb == ' ') {
                    foundB = true;
                } else strB += cb;
            }
        }

        if(foundA && foundB) {
            if(validString(strA)) {
                intA = stringToInt(strA);
            } else cout << strA << " is not a valid input" << endl;
            if(validString(strB)) {
                intB = stringToInt(strB);
            } else cout << strB << " is not a valid input" << endl;

            if(intA < intB) {
                cout << strA << endl;
                putString(strA + ' ', output);
                foundA = false;
                strA = "";
            }
            else {
                cout << strB << endl;
                putString(strB + ' ', output);
                foundB = false;
                strB = "";
            }
        }
    }


    //Put the rest.
    if(doneA) {
        while(fileB.get(cb)) {
            output.put(cb);
        }
    }
    else {
        while(fileA.get(ca)) {
            output.put(ca);
        }
    }
}

//Returns true if the string represents a valid integer.
bool validString(string s) {
    bool begining = 0;
    if(s.size() == 0) {
        return false;
    }
    if(s.size() == 1 && !isdigit(s[0])) {
        return false;
    }
    if(s[0] == '-') {
        begining = 1;
    }

    for(int i = begining; i < s.size(); i++) {
        if(!isdigit(s[i])) {
            return false;
        }
    }
    return true;
}


int stringToInt(string s) {
    int result;
    int begining(0);
    int factor(1);
    if(s[0] == '-') {
        begining = 1;
    }
    for(int i = s.size() - 1; i >= begining; i--) {
        result += (s[i] - '0') * factor;
        factor *= 10;
    }
    if(begining == 1) {
        return -result;
    } else return result;
}

void putString(string s, ofstream& output) {
    for(int i = 0 ; i < s.size(); i++) {
        output.put(s[i]);
    }
}