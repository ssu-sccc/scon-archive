#include <iostream>
using namespace std;
int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    if (A < B)
        cout << "Bus" << endl;
    else if (A == B)
        cout << "Anything" << endl;
    else
        cout << "Subway" << endl;
}