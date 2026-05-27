#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;

    vector<int> A(N);
    for(int &i : A) cin >> i;

    int a = 1, b = N; //a, b는 각각 반시계, 시계가 건너야하는 횡단보도 번호
    while(a != M && b != M-1){ 
        for(int i : A){
            if(i == a) a++;
            if(i == b) b--;
            if(a == M || b == M-1) break;
        }
    }

    cout << (a==M?"CW":"CCW") << "\n";
}