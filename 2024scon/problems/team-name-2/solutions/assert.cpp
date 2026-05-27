#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, C=0; cin >> N;
    assert(1 <= N && N <= 100);
    for(int i=1; i<=N; i++){
        string s; cin >> s;
        int upper = count_if(s.begin(), s.end(), [](char c){ return isupper(c) != 0; });
        int lower = count_if(s.begin(), s.end(), [](char c){ return islower(c) != 0; });
        int digit = count_if(s.begin(), s.end(), [](char c){ return isdigit(c) != 0; });
        int hyphen = count(s.begin(), s.end(), '-');
        if(upper <= lower && s.size() <= 10 && digit < s.size()) cout << s, C++;
        assert(1 <= s.size() && s.size() <= 20 && lower + upper + digit + hyphen == s.size());
    }
    assert(C == 1);
}