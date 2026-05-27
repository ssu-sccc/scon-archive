#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        if (A[i + 1] - A[i] != A[1] - A[0]) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    for (const int &a : A) {
        std::cout << a << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << "0 ";
    }
    std::cout << std::endl;

    return 0;
}
