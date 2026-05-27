import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] P = new int[3];
        int[] Y = new int[3];
        String[] S = new String[3];
        for(int i=0; i<3; i++){
            P[i] = sc.nextInt();
            Y[i] = sc.nextInt();
            S[i] = sc.next();
        }

        if(Y[0] < Y[1] && Y[1] < Y[2]) System.out.println("" + Y[0] % 100 + Y[1] % 100 + Y[2] % 100);
        if(Y[0] < Y[2] && Y[2] < Y[1]) System.out.println("" + Y[0] % 100 + Y[2] % 100 + Y[1] % 100);
        if(Y[1] < Y[0] && Y[0] < Y[2]) System.out.println("" + Y[1] % 100 + Y[0] % 100 + Y[2] % 100);
        if(Y[1] < Y[2] && Y[2] < Y[0]) System.out.println("" + Y[1] % 100 + Y[2] % 100 + Y[0] % 100);
        if(Y[2] < Y[0] && Y[0] < Y[1]) System.out.println("" + Y[2] % 100 + Y[0] % 100 + Y[1] % 100);
        if(Y[2] < Y[1] && Y[1] < Y[0]) System.out.println("" + Y[2] % 100 + Y[1] % 100 + Y[0] % 100);
        if(P[0] > P[1] && P[1] > P[2]) System.out.println("" + S[0].charAt(0) + S[1].charAt(0) + S[2].charAt(0));
        if(P[0] > P[2] && P[2] > P[1]) System.out.println("" + S[0].charAt(0) + S[2].charAt(0) + S[1].charAt(0));
        if(P[1] > P[0] && P[0] > P[2]) System.out.println("" + S[1].charAt(0) + S[0].charAt(0) + S[2].charAt(0));
        if(P[1] > P[2] && P[2] > P[0]) System.out.println("" + S[1].charAt(0) + S[2].charAt(0) + S[0].charAt(0));
        if(P[2] > P[0] && P[0] > P[1]) System.out.println("" + S[2].charAt(0) + S[0].charAt(0) + S[1].charAt(0));
        if(P[2] > P[1] && P[1] > P[0]) System.out.println("" + S[2].charAt(0) + S[1].charAt(0) + S[0].charAt(0));

        sc.close();
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> O = {0, 1, 2};
    do{
        cout << "if(Y[" << O[0] << "] < Y[" << O[1] << "] && Y[" << O[1] << "] < Y[" << O[2] << "]) ";
        cout << "System.out.println(\"\" + Y[" << O[0] << "] % 100 + Y[" << O[1] << "] % 100 + Y[" << O[2] << "] % 100);\n";
    }while(next_permutation(O.begin(), O.end()));

    do{
        cout << "if(P[" << O[0] << "] > P[" << O[1] << "] && P[" << O[1] << "] > P[" << O[2] << "]) ";
        cout << "System.out.println(\"\" + S[" << O[0] << "].charAt(0) + S[" << O[1] << "].charAt(0) + S[" << O[2] << "].charAt(0));\n";
    }while(next_permutation(O.begin(), O.end()));
}
*/