import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] A = new int[N + 1];
        int sameIdx = -1, diffIdx = -1;
        int half = (N + 1) >> 1, queryCnt = 0;
        for (int i = 1; i <= half; i++) {
            System.out.printf("? %d\n", i);
            A[i] = Integer.parseInt(br.readLine());
            System.out.printf("? %d\n", N - i + 1);
            A[N - i + 1] = Integer.parseInt(br.readLine());
            if (A[i] == A[N - i + 1])
                sameIdx = i;
            else
                diffIdx = i;
            queryCnt += 2;
            if (queryCnt % 10 == 0) {
                if (sameIdx == -1) {
                    System.out.printf("? %d\n", diffIdx);
                    int l = Integer.parseInt(br.readLine());
                    System.out.printf("? %d\n", N - diffIdx + 1);
                    int r = Integer.parseInt(br.readLine());
                    queryCnt += 2;
                    if (A[diffIdx] != l) {
                        for (int j = 1; j <= i; j++) {
                            A[j] ^= 1;
                            if (j != N - j + 1)
                                A[N - j + 1] ^= 1;
                        }
                    }
                } else if (diffIdx == -1) {
                    System.out.printf("? %d\n", sameIdx);
                    int l = Integer.parseInt(br.readLine());
                    System.out.printf("? %d\n", N - sameIdx + 1);
                    int r = Integer.parseInt(br.readLine());
                    queryCnt += 2;
                    if (A[sameIdx] != l) {
                        for (int j = 1; j <= i; j++) {
                            A[j] ^= 1;
                            if (j != N - j + 1)
                                A[N - j + 1] ^= 1;
                        }
                    }
                } else {
                    System.out.printf("? %d\n", diffIdx);
                    int dl = Integer.parseInt(br.readLine());
                    System.out.printf("? %d\n", sameIdx);
                    int sl = Integer.parseInt(br.readLine());
                    queryCnt += 2;
                    if (dl != A[diffIdx] && sl != A[sameIdx]) {
                        for (int j = 1; j <= i; j++) {
                            A[j] ^= 1;
                            if (j != N - j + 1)
                                A[N - j + 1] ^= 1;
                        }
                    } else if (dl != A[diffIdx] && sl == A[sameIdx]) {
                        for (int j = 1; j <= i; j++) {
                            int tmp = A[j];
                            A[j] = A[N - j + 1];
                            A[N - j + 1] = tmp;
                        }
                    } else if (dl == A[diffIdx] && sl != A[sameIdx]) {
                        for (int j = 1; j <= i; j++) {
                            int tmp = A[j];
                            A[j] = A[N - j + 1];
                            A[N - j + 1] = tmp;
                            A[j] ^= 1;
                            if (j != N - j + 1)
                                A[N - j + 1] ^= 1;
                        }
                    }
                }
            }
        }
        sb.append('!');
        for (int i = 1; i <= N; i++)
            sb.append(' ').append(A[i]);
        System.out.println(sb);
    }
}