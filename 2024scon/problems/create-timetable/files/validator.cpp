#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 15, "N");
    int sum = 0;
    inf.readEoln();
    for (int i = 0; i < n; i++) {
        int m = inf.readInt(1, 15, format("A_%d", i));
        inf.readEoln();

        sum += m;
        ensuref(sum <= 15, "sum must be equal or less than 15, but got %d", sum);

        for (int j = 0; j < m; j++) {
            int a = inf.readInt(1, 22, "credit");
            inf.readSpace();
            int b = inf.readInt(1, 7, "day");
            inf.readSpace();

            string c = inf.readToken("[0-9]{2}:[0-9]{2}", "start");
            int e = atoi(c.substr(0, 2).c_str());
            int f = atoi(c.substr(3, 2).c_str());
            ensuref(0 <= e && e <= 23, "0 <= hh <= 23");
            ensuref(0 <= f && f <= 59, "0 <= mm <= 59");

            inf.readSpace();

            string d = inf.readToken("[0-9]{2}:[0-9]{2}", "end");
            int g = atoi(d.substr(0, 2).c_str());
            int h = atoi(d.substr(3, 2).c_str());
            ensuref(0 <= g && g <= 23, "0 <= hh <= 23");
            ensuref(0 <= h && h <= 59, "0 <= mm <= 59");

            int x = e * 60 + f, y = g * 60 + h;
            ensuref(x < y, "x < y");

            inf.readEoln();
        }
    }
    
    inf.readEof();
}
