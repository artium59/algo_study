import java.util.Scanner;

public class Main {
    static int[][] paper = new int[10][10];
    static int[] counts = {0, 5, 5, 5, 5, 5};
    static int ans = 1234567890;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
                paper[i][j] = sc.nextInt();
        }

        search(0, 0);
        ans = ans == 1234567890 ? -1 : ans;

        System.out.print(ans);
    }

    static void search(int height, int cnt) {
        for (int i = height; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (paper[i][j] == 1) {
                    for (int k = 5; k > 0; k--) {
                        if (counts[k] > 0 && paper[i][j] == 1 && overlap(i, j, k)) {
                            paper[i][j] = 0;
                            erase(i, j, k); counts[k]--;
                            search(i, cnt+1);
                            reveal(i, j, k); counts[k]++;
                        }
                    }
                    return;
                }
            }
        }

        if (check()) ans = Math.min(ans, cnt);
    }

    static boolean overlap(int y, int x, int c) {
        int cnt = 0;

        for (int i = 0; i < c && y+i < 10; i++) {
            for (int j = 0; j < c && x+j < 10; j++) {
                cnt += paper[y+i][x+j];
            }
        }

        return cnt == c*c;
    }

    static void erase(int y, int x, int c) {
        for (int i = 0; i < c && y+i < 10; i++) {
            for (int j = 0; j < c && x+j < 10; j++) {
                paper[y+i][x+j] = 0;
            }
        }
    }

    static void reveal(int y, int x, int c) {
        for (int i = 0; i < c && y+i < 10; i++) {
            for (int j = 0; j < c && x+j < 10; j++) {
                paper[y+i][x+j] = 1;
            }
        }
    }

    static boolean check() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (paper[i][j] == 1) return false;
            }
        }

        return true;
    }
}
