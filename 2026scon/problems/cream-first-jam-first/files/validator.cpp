#include "testlib.h"
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int N = inf.readInt(1, 200, "N");
    inf.readEoln();

    string s = inf.readToken("[CJS]{1,200}", "s");
    inf.readEoln();

    ensuref((int)s.size() == N, "Length of s must be exactly N.");
    ensuref(s.back() == 'S', "The string must end with 'S'.");

    inf.readEof();
    return 0;
}