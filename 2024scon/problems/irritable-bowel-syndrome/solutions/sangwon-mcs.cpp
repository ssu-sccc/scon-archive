#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, stress = 0, answer = 0;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int a;
        cin >> a;

        stress = max(0, stress + a);
        if(stress >= m) answer ++;
    }

    cout << answer << '\n';

    return 0;
}