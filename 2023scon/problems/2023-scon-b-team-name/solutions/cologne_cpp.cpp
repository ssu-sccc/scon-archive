#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

struct PYS {
    int num;
    std::string str1;
    char ch;
};

bool sortBySecond(const PYS &a, const PYS &b) {
    return a.str1 < b.str1;
}

bool sortByFirstDescending(const PYS &a, const PYS &b) {
    return a.num > b.num;
}

int main() {
    std::vector<PYS> PYSList;
    for (int i = 0; i < 3; ++i) {
        int num;
        std::string str1, str2;
        std::cin >> num >> str1 >> str2;
        PYSList.push_back({num, str1, str2[0]});
    }

    std::sort(PYSList.begin(), PYSList.end(), sortBySecond);

    for (const auto &elem : PYSList) {
        std::cout << elem.str1.substr(2);
    }
    std::cout << std::endl;

    std::sort(PYSList.begin(), PYSList.end(), sortByFirstDescending);

    for (const auto &elem : PYSList) {
        std::cout << elem.ch;
    }
    std::cout << std::endl;

    return 0;
}
