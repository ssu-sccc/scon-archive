#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        int x; cin >> x;
        A[x] = i; //x번 횡단보도의 순열에서의 위치
    }

    int r_cnt=0, r_i=0, l_cnt=0, l_i=0;
    for(int i = 1; i < M; i++){ //1번 횡단보도 부터 M-1번 횡단보도까지 차례대로
        int t = A[i];
        if(t < l_i) l_cnt++; //현재 횡단보도의 위치가 이전 횡단보도 위치보다 앞에 있다면 주기 한 번을 기다렸음
        l_i = t; 
    }

    for(int i = N; i >= M; i--){ //N번 횡단보도 부터 M번 횡단보도까지 차례대로
        int t = A[i];
        if(t < r_i) r_cnt++; //현재 횡단보도의 위치가 이전 횡단보도 위치보다 앞에 있다면 주기 한 번을 기다렸음
        r_i = t;
    }

    if(l_cnt == r_cnt){
        cout << (l_i < r_i ? "CW" : "CCW") << "\n"; 
    }
    else{
        cout << (l_cnt < r_cnt ? "CW" : "CCW") << "\n"; 
    }
}