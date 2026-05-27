import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) a[i] = sc.nextInt();
        long sum = 0; int now = a[n-1];
        for(int i=n-1; i>=0; i--){
            if(a[i] < now) now = a[i];
            sum += now;
        }
        System.out.println(sum);
    }
}