import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        for (int i = 0; i < N - 1; i++) {
            if (A[i + 1] - A[i] != A[1] - A[0]) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
        for (int a : A) {
            System.out.print(a + " ");
        }
        System.out.println();

        for (int i = 0; i < N; i++) {
            System.out.print("0 ");
        }
        System.out.println();
    }
}
