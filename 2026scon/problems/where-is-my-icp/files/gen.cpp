#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int type = atoi(argv[1]);
    string target = "ICPC";

    // all valid subsequences of "ICPC" (non-empty, preserving order)
    vector<string> subs;
    for (int mask = 1; mask < (1 << 4); mask++) {
        string s;
        for (int i = 0; i < 4; i++)
            if ((mask >> i) & 1) s += target[i];
        subs.push_back(s);
    }

    string S, T;
    int tlen;

    // compute needed chars
    auto getNeed = [&](const string& s) {
        map<char,int> need;
        for (char c : target) need[c]++;
        for (char c : s) need[c]--;
        return need;
    };

    auto fillT = [&](int len, map<char,int> need, bool satisfy) -> string {
        string t(len, 'A');
        for (int i = 0; i < len; i++)
            t[i] = (char)('A' + rnd.next(0, 25));

        if (satisfy) {
            // 1. 현재 T에 어떤 문자가 있는지 확인
            map<char,int> cur;
            for (char c : t) cur[c]++;

            // 2. 정말로 부족한 문자가 무엇인지 리스트업
            vector<char> flat_deficit;
            for (auto& [c, n] : need) {
                int d = n - cur[c];
                for (int i = 0; i < d; i++) flat_deficit.push_back(c);
            }

            // 3. 자리가 부족하면 부족한 대로, 있으면 있는 대로 섞어서 덮어쓰기
            if (!flat_deficit.empty()) {
                vector<int> positions(len);
                iota(positions.begin(), positions.end(), 0);
                shuffle(positions.begin(), positions.end());

                // 남은 공간(len)과 채워야 할 문자 개수 중 작은 값만큼만 반복
                int limit = min((int)len, (int)flat_deficit.size());
                for (int i = 0; i < limit; i++) {
                    t[positions[i]] = flat_deficit[i];
                }
            }
        } else {
            // 강제로 실패하게 만드는 로직 (기존과 동일)
            vector<char> needed;
            for (auto& [c, n] : need) if (n > 0) needed.push_back(c);
            if (!needed.empty()) {
                char rm = needed[rnd.next(0, (int)needed.size() - 1)];
                char safe = 'Z';
                for (char c = 'A'; c <= 'Z'; c++) {
                    if (need.find(c) == need.end() || need[c] == 0) { safe = c; break; }
                }
                for (int i = 0; i < len; i++) if (t[i] == rm) t[i] = safe;
            }
        }
        return t;
    };

    if (type == 0) {
        S = subs[rnd.next(0, (int)subs.size() - 1)];
        tlen = rnd.next(1, 100);
        T = fillT(tlen, getNeed(S), false); // random, no guarantee
        // actually for type 0 just pure random
        T = "";
        for (int i = 0; i < tlen; i++)
            T += (char)('A' + rnd.next(0, 25));
    } else if (type == 1) {
        S = subs[rnd.next(0, (int)subs.size() - 1)];
        tlen = rnd.next(4, 100);
        T = fillT(tlen, getNeed(S), true);
    } else if (type == 2) {
        S = subs[rnd.next(0, (int)subs.size() - 1)];
        tlen = rnd.next(1, 100);
        T = fillT(tlen, getNeed(S), false);
    } else if (type == 3) {
        S = subs[rnd.next(0, (int)subs.size() - 1)];
        tlen = 100;
        T = fillT(tlen, getNeed(S), true);
    } else if (type == 4) {
        S = subs[rnd.next(0, (int)subs.size() - 1)];
        tlen = 100;
        T = fillT(tlen, getNeed(S), false);
    } else if (type == 5) { // n: min (1), m: min (1)
        vector<string> min_subs;
        for(auto& s : subs) if(s.length() == 1) min_subs.push_back(s);
        S = min_subs[rnd.next(0, (int)min_subs.size() - 1)];
        tlen = 1;
        T = fillT(tlen, getNeed(S), rnd.next(0, 1)); 
    } else if (type == 6) { // n: max (4), m: max (100)
        S = "ICPC";
        tlen = 100;
        T = fillT(tlen, getNeed(S), rnd.next(0, 1));
    } else if (type == 7) { // n: min (1), m: max (100)
        vector<string> min_subs;
        for(auto& s : subs) if(s.length() == 1) min_subs.push_back(s);
        S = min_subs[rnd.next(0, (int)min_subs.size() - 1)];
        tlen = 100;
        T = fillT(tlen, getNeed(S), rnd.next(0, 1));
    } else { // n: max (4), m: min (1)
        S = "ICPC";
        tlen = 1;
        T = fillT(tlen, getNeed(S), true); // S가 이미 완성이라 T는 아무거나 한 글자면 됨
    }

    println((int)S.length());
    println(S);
    println((int)T.length());
    println(T);
    return 0;
}
