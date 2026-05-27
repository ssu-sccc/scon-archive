#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    int upper = count_if(s.begin(), s.end(), [](char c){ return isupper(c) != 0; });
    int lower = count_if(s.begin(), s.end(), [](char c){ return islower(c) != 0; });
    int digit = count_if(s.begin(), s.end(), [](char c){ return isdigit(c) != 0; });
    return upper <= lower && s.size() <= 10 && digit < s.size();
}

string build(int up, int lo, int di){
    string res;
    for(int i=0; i<up; i++) res += char(rnd.next(0,25) + 'A');
    for(int i=0; i<lo; i++) res += char(rnd.next(0,25) + 'a');
    for(int i=0; i<di; i++) res += char(rnd.next(0, 9) + '0');
    shuffle(res.begin(), res.end());
    return res;
}

string gen(int cond1, int cond2, int cond3){
    if(cond3 > cond2) return "";

    int digit = cond3, alpha = cond2 - cond3;
    if((cond1 + alpha) % 2 != 0) return "";
    if(abs(cond1) > alpha) return "";

    // lower + upper = alpha
    // lower - upper = cond1
    int lower = (alpha + cond1) / 2;
    int upper = (alpha - cond1) / 2;
    return build(upper, lower, digit);
}

string gen(tuple<int,int,int> t){
    return gen(get<0>(t), get<1>(t), get<2>(t));
}

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = opt<int>("n");
    vector<string> S;

    // cond1: {-2, -1, 0, 1, 2}
    // cond2: {9, 10, 11}
    // cond3: {0, 1, N-1, N, len-1, len}

    vector<tuple<int,int,int>> fail, pass;
    for(auto cond1 : {-2, -1, 0, 1, 2}){
        for(auto cond2 : {9, 10, 11}){
            for(auto cond3 : {0, 1, cond2-1, cond2, N-1, N}){
                auto s = gen(cond1, cond2, cond3);
                if(!s.empty()) (check(s) ? pass : fail).emplace_back(cond1, cond2, cond3);
            }
        }
    }

    vector<string> V;
    for(auto i : fail) V.push_back(gen(i));
    while(V.size() + 1 < N) V.push_back(gen(fail[rnd.next(0,(int)pass.size()-1)]));
    shuffle(V.begin(), V.end());
    
    int pos = rnd.next((int)V.size() - 10, (int)V.size());
    V.insert(V.begin()+pos, gen(pass[rnd.next(0,(int)pass.size()-1)]));

    cout << N << "\n";
    for(auto i : V) cout << i << "\n";
}