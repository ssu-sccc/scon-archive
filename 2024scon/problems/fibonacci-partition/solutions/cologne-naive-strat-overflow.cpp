#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    uint64_t N;
    cin >> N;
    vector<uint64_t> A = {0, 1};
    while (A.size() != N)
    {
        A.push_back(A[A.size() - 1] + A[A.size() - 2]);
    }
    uint64_t sumA = 0;
    for (uint64_t num : A)
    {
        sumA += num;
    }
    uint64_t x = sumA / 2;
    uint64_t y = sumA / 2;
    vector<uint64_t> a, b;
    for (int64_t i = N - 1; i >= (N % 3 == 1 ? 1 : 0); i--)
    {
        if (x >= A[i])
        {
            x -= A[i];
            a.push_back(i + 1);
        }
        else
        {
            y -= A[i];
            b.push_back(i + 1);
        }
    }
    cout << a.size() << endl;
    for (uint64_t num : a)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << b.size() << endl;
    for (uint64_t num : b)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
