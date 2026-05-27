P, Y, S = [], [], []

for i in range(3):
    p, y, s = input().split()
    P.append(int(p))
    Y.append(int(y))
    S.append(s)

if Y[0] < Y[1] < Y[2]: print(Y[0] % 100, Y[1] % 100, Y[2] % 100, sep='')
if Y[0] < Y[2] < Y[1]: print(Y[0] % 100, Y[2] % 100, Y[1] % 100, sep='')
if Y[1] < Y[0] < Y[2]: print(Y[1] % 100, Y[0] % 100, Y[2] % 100, sep='')
if Y[1] < Y[2] < Y[0]: print(Y[1] % 100, Y[2] % 100, Y[0] % 100, sep='')
if Y[2] < Y[0] < Y[1]: print(Y[2] % 100, Y[0] % 100, Y[1] % 100, sep='')
if Y[2] < Y[1] < Y[0]: print(Y[2] % 100, Y[1] % 100, Y[0] % 100, sep='')
if P[0] > P[1] > P[2]: print(S[0][0], S[1][0], S[2][0], sep='')
if P[0] > P[2] > P[1]: print(S[0][0], S[2][0], S[1][0], sep='')
if P[1] > P[0] > P[2]: print(S[1][0], S[0][0], S[2][0], sep='')
if P[1] > P[2] > P[0]: print(S[1][0], S[2][0], S[0][0], sep='')
if P[2] > P[0] > P[1]: print(S[2][0], S[0][0], S[1][0], sep='')
if P[2] > P[1] > P[0]: print(S[2][0], S[1][0], S[0][0], sep='')

'''
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> O = {0, 1, 2};
    do{
        cout << "if Y[" << O[0] << "] < Y[" << O[1] << "] < Y[" << O[2] << "]: ";
        cout << "print(Y[" << O[0] << "] % 100, Y[" << O[1] << "] % 100, Y[" << O[2] << "] % 100, sep='')\n";
    }while(next_permutation(O.begin(), O.end()));

    do{
        cout << "if P[" << O[0] << "] > P[" << O[1] << "] > P[" << O[2] << "]: ";
        cout << "print(S[" << O[0] << "][0], S[" << O[1] << "][0], S[" << O[2] << "][0], sep='')\n";
    }while(next_permutation(O.begin(), O.end()));
}
'''