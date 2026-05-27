#include "testlib.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    string type_str = opt<string>(1);
    char type = type_str[0]; 
    int n = opt<int>(2);
    string s = "";
    if (n > 1) {
        s = string(n - 1, type);
    }
    s += 'S';
    cout << n << "\n";
    cout << s << "\n";
    return 0;
}