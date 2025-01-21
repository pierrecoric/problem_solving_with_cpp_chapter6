/*
37. Write some C++ code that will read a line of text and echo the line with all
uppercase letters deleted.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char c;
    cout << "Input something: ";
    do {
        cin.get(c);
        if(! isupper(c)) {
            cout << c;
        }
    } while(c != '\n');
    cout << endl;
    return 0;
}