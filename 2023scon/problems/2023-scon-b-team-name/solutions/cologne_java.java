import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

    static class PYS {
        int num;
        String str1;
        char ch;

        PYS(int num, String str1, char ch) {
            this.num = num;
            this.str1 = str1;
            this.ch = ch;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<PYS> PYSList = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            int num = scanner.nextInt();
            String str1 = scanner.next();
            char ch = scanner.next().charAt(0);
            PYSList.add(new PYS(num, str1, ch));
        }

        PYSList.sort(Comparator.comparing(a -> a.str1));

        for (PYS elem : PYSList) {
            System.out.print(elem.str1.substring(2));
        }
        System.out.println();

        PYSList.sort((a, b) -> Integer.compare(b.num, a.num));

        for (PYS elem : PYSList) {
            System.out.print(elem.ch);
        }
        System.out.println();
    }
}
