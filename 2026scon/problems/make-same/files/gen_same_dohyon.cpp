#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int N = 2000;
    printf("%d\n", N);
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)
    	A[i] = 49997850;
    A[1999] = 52880554;
    A[2000] = 51415146;
    for(int i=1;i<=N;i++)
    	if(i == 1)
    		printf("%d", A[i]);
    	else
    		printf(" %d", A[i]);
    printf("\n");
}
