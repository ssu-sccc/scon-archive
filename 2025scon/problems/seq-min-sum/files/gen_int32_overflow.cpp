#include "testlib.h"
#include <iostream>
 
#define N_MAX 500'000
#define A_MAX 1'000'000
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    int N = rnd.next(INT_MAX / N_MAX + 1, N_MAX);
 
    cout << N << '\n';
 
    for(int i=0; i<N; i++) {
        int a = rnd.next(INT_MAX / N, A_MAX);
        cout << a << " \n"[i == N-1];
    }
 
    return 0;
}