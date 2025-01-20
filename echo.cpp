//Example form the book.

#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Enter a line of input and the program will echo it:" << endl;
    char symbol;
    string s;
    do {
        cin.get(symbol);
        s += symbol;
        cout << symbol;
    } while (symbol != '\n');
    cout << "and also here it is as a string: " << s << endl;
    cout << "demonstration is finished" << endl;
    return 0;
}