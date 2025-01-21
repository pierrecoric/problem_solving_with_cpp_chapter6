#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ifstream input;
    input.open("morestuf.dat");
    char next; 
    input.get(next);
    while (! input.eof( )) {
        cout << next;
        input.get(next);
    }
    input.close();
    return 0;
}