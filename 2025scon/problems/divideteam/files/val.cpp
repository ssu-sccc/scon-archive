#include "testlib.h"

int main(int argc,char *argv[]) {
    registerValidation(argc, argv);  // testlib 초기화

    // 첫 번째 줄: 정수 N (1 ≤ N ≤ 1,000,000)
    int N = inf.readInt(1, 1'000'000, "N");
    inf.readEoln(); // 줄 끝 확인

    // 두 번째 줄: N개의 정수 A_i (0 ≤ A_i ≤ 1)
    for (int i = 0; i < N; i++) {
        if (i > 0) inf.readSpace(); // 숫자 사이에는 공백이 있어야 함
        inf.readInt(0, 1, "A_i");
    }
    inf.readEoln(); // 줄 끝 확인

    // 세 번째 줄: N개의 정수 B_i (0 ≤ B_i ≤ 1,000,000)
    for (int i = 0; i < N; i++) {
        if (i > 0) inf.readSpace(); // 숫자 사이에는 공백이 있어야 함
        inf.readInt(0, 1'000'000, "B_i");
    }
    inf.readEoln(); // 줄 끝 확인

    inf.readEof(); // 파일 끝 확인

    return 0;
}
