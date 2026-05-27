#include <bits/stdc++.h>

using namespace std;

int main(){
    int s, c;
    int t1, t2, t3, t4;
    cin>> t1>> t2>> t3>>  t4;
    s = t1 + t4;
    c = t2 + t3 * 2;
    cout << min(s / 3, c / 6);
    return 0;
}