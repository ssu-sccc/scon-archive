#include <bits/stdc++.h>
using namespace std;

int f(string s){
    for(int i=0, j=0, k=0; i<s.size(); i=j, k++){
        while(j < s.size() && s[i] == s[j]) j++;
        if(k < 2 && s[i] != 'C' && s[i] != 'J') return 2;
        if(k == 2 && s[i] != 'S') return 2;
    }
    return s[0] == 'C' ? 0 : 1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A[3]={0}; string S, T;
    cin >> N >> S;
    for(auto c : S){
        T += c;
        if(c == 'S') A[f(T)] += 1, T.clear();
    }
    cout << A[0] << "\n" << A[1] << "\n";
}