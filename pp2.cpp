/*
2. Write a program that takes its input from a file of numbers of type double
and outputs the average of the numbers in the file to the screen. The file
contains nothing but numbers of type double separated by blanks and/or
line breaks. If this is being done as a class assignment, obtain the file name
from your instructor.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

double stringToDouble(string s);
bool validDoubleString(string s);
double computeAverageFromFile(istream& input);
void putLine(ofstream& output);


int main() {
    ifstream numbers;
    numbers.open("numbers_2.dat");
    cout << "File open" << endl << endl;
    double average = computeAverageFromFile(numbers);
    cout << endl << "The average of the numbers found in this file is: " << average;
    numbers.close();
    cout << endl << "End of program." << endl;

    return 0;
}

double stringToDouble(string s) {
    //Initialize the result to 0.
    double result(0);

    //Check for empty string
    if(s.size() == 0) {
        return 0;
    }

    //Assess wheter the string represents a negative number.
    bool neg(false);
    if(s[0] == '-') {
        neg = true;
    }

    //Find in which position is the decimal point and if there is one
    bool decimal(false);
    int decimalIndex(0);
    //Iterate to determine this.
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '.' || s[i] == ',') {
            decimal = true;
            decimalIndex = i;
            break;
        }
    }

    //The begining of the digit is 1 in case of negative number
    int begining(0);
    if (neg) {
        begining = 1;
    }

    //If the number does not contain decimal point, the decimal index is equal to the size of the string, so the second loop does not run.
    if(!decimal) {
        decimalIndex = s.size();
    }
    
    //Initialize the factor to 1.
    double factor = 1;

    //Iterate from the decimal index to the begining of the string. 
    //Add to the result and multiply the factor by 10.
    for(int i = decimalIndex - 1; i >= begining; i--) {
        double n = s[i] - '0';
        result += n * factor;
        factor *= 10;
    }

    factor = 0.1;

    //Iterate from the decimal index of the string to the end of the string.
    //Add to the result and divide the factor by 10.
    for(int i = decimalIndex + 1; i < s.size(); i ++) {
        double n = s[i] - '0';
        result += n * factor;
        factor /= 10;
    }

    //In case of negative string, return the result negatively.
    if (neg) {
        result = -result;
    }

    return result;
}


bool validDoubleString(string s) {
    //Return true if the string represent a double.
    //- or digit in first position
    if(s[0] != '-' && !isdigit(s[0])) {
        return false;
    }
    //only digit in the last position
    if(!isdigit(s[s.size() - 1])) {
        return false;
    }

    //contains a coma or a dot somewhere inside (only one)
    bool decimal(false);
    int begining(0);
    if (s[0] == '-') {
        begining = 1;
    }

    //Iterate and check that the format is correct.
    for (int i = begining; i < s.size(); i++) {
        //check if the character is not a digit;
        if(!isdigit(s[i])) {
            if(s[i] == '.' || s[i] == ',') {
                if(!decimal) {
                    decimal = true;
                } else return false;
            } else return false;
        }
    }

    return true;
}

double computeAverageFromFile(istream& input) {
    string current;
    char c;
    double average(0);
    int counter(0);

    while (!input.eof()) {
        input.get(c);
        current += c;
        if (c == ' ' || c == '\n') {
            current.pop_back();
            if(validDoubleString(current)) {
                counter ++;
                cout << "#" << counter << " number found: " << current << endl;
                average += stringToDouble(current);
                
            } else cout << "\t" << current << " is not a valid string -> ignore" << endl;
            current = "";
        }
    }

    //Account for the last item.
    current.pop_back();
    if(validDoubleString(current)) {
        counter ++;
        cout << "#" << counter << " number found: " << current << endl;
        average += stringToDouble(current);
    } else cout << "\t" << current << " is not a valid string -> ignore" << endl;

    //Make sure to avoid division by 0.
    if (counter > 0) {
        return average / counter;
    } else return 0;
    
}


void putLine(ofstream& output) {
    char c = '\0';
    while(true) {
        cin.get(c);
        if (c == '\n') {
            break;
        }
        output.put(c);
    }
    output.put(' ');
}