import java.util.Scanner;

public class Main {
    static boolean[][] paper = new boolean[100][100];
    static int t, n, m, ans=0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        t = sc.nextInt();
        while (t-- > 0) {
            n = sc.nextInt();
            m = sc.nextInt();
            coloring();
        }

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (paper[i][j]) ans++;
            }
        }

        System.out.println(ans);
    }

    static void coloring() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                paper[n+i][m+j] = true;
        }
    }
}
