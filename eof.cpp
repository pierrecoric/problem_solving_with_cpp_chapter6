#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream input;
    input.open("test.jpg");
    char next; 
    input.get(next);
    int counter(0);
    while (! input.eof( )) {
        cout << next;
        input.get(next);
        counter ++;
    }
    input.close();
    cout << endl << counter << endl;
    return 0;
}