#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool e(vector<char> v) {
    int d=v[0]=='T';
    for(int i=1;i<v.size();i+=2) {
        if(v[i]=='&') d&=(v[i+1]=='T');
        else d|=(v[i+1]=='T');
    }
    return d;
}

char r(char c) {
    if(c=='&') return '|';
    if(c=='|') return '&';
    if(c=='T') return 'F';
    return 'T';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<char> v(n);
    int t=0,f=0,a=0,o=0;
    for(char &c:v) {
        cin >> c;
        if(c=='T') t++;
        if(c=='F') f++;
        if(c=='&') a++;
        if(c=='|') o++;
    }
    
    char c; cin >> c;
    if((c=='T') == e(v)) {cout << 0; return 0;}
    for(int i=0;i<n;i++) {
        v[i]=r(v[i]);
        if(e(v) == (c=='T')) {cout << 1; return 0;}
        v[i]=r(v[i]);
    }
    cout << 2;
    return 0;
}