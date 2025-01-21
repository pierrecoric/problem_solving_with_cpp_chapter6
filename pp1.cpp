/*
1. Write a program that will search a file of numbers of type int and write the
largest and the smallest numbers to the screen. The file contains nothing
but numbers of type int separated by blanks or line breaks. If this is being
done as a class assignment, obtain the file name from your instructor.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int stringToInt(string s);
void find(istream& input);
void updateMinMax(int current, int& min, int& max);

int main() {
    ifstream f;
    f.open("numbers.dat");
    find(f);
    f.close();
    cout << "End of demo." << endl;
    return 0;
}

int stringToInt(string s) {
    int result(0);
    bool negative = false;
    int factor(1);
    for(int i = s.length() - 1; i >= 0; i--) {
        //check if the string represent a negative number.
        if(s[i] == '-') {
            negative = true;
        }
        else {
            result += (int(s[i]) - '0') * factor;
            factor *= 10;
        }
    }
    if(negative) {
        return 0 - result;
    } else return result;
}

void find(istream& input) {
    char next;
    int min, max, current;
    string digit;
    bool init = false;
    input.get(next);
    digit += next;
    while(!input.eof()) {
        input.get(next);
        digit += next;
        //When encountering a blank space.
        if(next == ' ') {
            //Initialization of min and max.
            if(!init) {
                digit.pop_back();
                current = stringToInt(digit);
                min = current;
                max = current;
                digit = "";
                init = true;
            }
            //Normal processing of the rest of the file
            else {
                digit.pop_back();
                current = stringToInt(digit);
                updateMinMax(current, min, max);
                digit = "";
            }
        }
    }
    //Processing of the last digit.
    digit.pop_back();
    current = stringToInt(digit);
    updateMinMax(current, min, max);
    
    
    cout << "The min is: " << min << endl;
    cout << "The max is: " << max << endl;
}

void updateMinMax(int current, int& min, int& max) {
    if(current < min) {
        min = current;
    }
    if(current > max) {
        max = current;
    }
}

