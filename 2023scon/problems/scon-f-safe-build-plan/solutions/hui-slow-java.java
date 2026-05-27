import java.util.Scanner;

public class Main{
    static int n, m;
    static boolean[][] g;

    static boolean isFinished(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && !g[i][j]) return false;
            }
        }
        return true;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        g = new boolean[n][n];
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) g[i][j] = false;
        for(int i=0; i<m; i++){
            int u = sc.nextInt() - 1;
            int v = sc.nextInt() - 1;
            g[u][v] = g[v][u] = true;
        }
        int res = 0;
        while(!isFinished()){
            int a = -1, b = -1, c = -1;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        if(i == j || j == k || k == i) continue;
                        int x = g[i][j] ? 0 : 1;
                        int y = g[j][k] ? 0 : 1;
                        int z = g[k][i] ? 0 : 1;
                        if(x + y + z == 1){ a = i; b = j; c = k; }
                    }
                }
            }
            if(a != -1){
                g[a][b] = g[a][c] = g[b][a] = g[b][c] = g[c][a] = g[c][b] = true;
                continue;
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    for(int k=0; k<n; k++){
                        if(i == j || j == k || k == i) continue;
                        int x = g[i][j] ? 0 : 1;
                        int y = g[j][k] ? 0 : 1;
                        int z = g[k][i] ? 0 : 1;
                        if(x + y + z == 2){ a = i; b = j; c = k; }
                    }
                }
            }
            if(a != -1){
                g[a][b] = g[a][c] = g[b][a] = g[b][c] = g[c][a] = g[c][b] = true;
                res += 1; continue;
            }
        }
        System.out.println(res);
        sc.close();
    }
}