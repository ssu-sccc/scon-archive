#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int l = opt<int>("l"), r = opt<int>("r"), mod = opt<int>("mod");
    vector<int> vec;
    for(int i=l; i<=r; i++) if(i % 3 == mod) vec.push_back(i);
    cout << vec[rnd.next(0, (int)vec.size()-1)] << "\n";
    return 0;
}