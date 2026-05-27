#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int k = opt<int>("k");
    int mx = opt<int>("mx");

    vector<int> a(n);
    for (int &v : a)
        v = rnd.next(1, mx);
    sort(a.begin(), a.end());
    reverse(a.end() - k, a.end());

    println(n);
    println(a);

    return 0;
}