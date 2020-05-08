import java.util.Scanner;

public class Main {
    static int[][] board = new int[500][500];
    static int r, c, ans = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        r = sc.nextInt(); c = sc.nextInt();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                board[i][j] = sc.nextInt();
        }

        ans = Math.max(ans, cyan());
        ans = Math.max(ans, yellow());
        ans = Math.max(ans, orange());
        ans = Math.max(ans, green());
        ans = Math.max(ans, pink());

        System.out.println(ans);
    }

    static int cyan() {
        int ret = 0, tmp;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                tmp = 0;
                for (int k = 0; k < 4 && i+k < r; k++)
                    tmp += board[i+k][j];
                ret = Math.max(ret, tmp);

                tmp = 0;
                for (int k = 0; k < 4 && j+k < c; k++)
                    tmp += board[i][j+k];
                ret = Math.max(ret, tmp);
            }
        }

        return ret;
    }

    static int yellow() {
        int ret = 0, tmp;

        for (int i = 0; i < r-1; i++) {
            for (int j = 0; j < c-1; j++) {
                tmp = board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1];
                ret = Math.max(ret, tmp);
            }
        }

        return ret;
    }

    static int orange() {
        int ret = 0, three;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                three = 0;

                for (int k = 0; k < 3 && i+k < r; k++)
                    three += board[i+k][j];
                if (i+2 < r && j+1 < c) {
                    ret = Math.max(ret, three+board[i][j+1]);
                    ret = Math.max(ret, three+board[i+2][j+1]);
                }
                if (i+2 < r && 0 <= j-1) {
                    ret = Math.max(ret, three+board[i][j-1]);
                    ret = Math.max(ret, three+board[i+2][j-1]);
                }

                three = 0;
                for (int k = 0; k < 3 && j+k < c; k++)
                    three += board[i][j+k];
                if (i+1 < r && j+2 < c) {
                    ret = Math.max(ret, three+board[i+1][j]);
                    ret = Math.max(ret, three+board[i+1][j+2]);
                }
                if (0 <= i-1 && j+2 < c) {
                    ret = Math.max(ret, three+board[i-1][j]);
                    ret = Math.max(ret, three+board[i-1][j+2]);
                }
            }
        }

        return ret;
    }

    static int green() {
        int ret = 0, two;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (j+1 < c) {
                    two = board[i][j] + board[i][j+1];

                    if (i+1 < r) {
                        if (j+2 < c) ret = Math.max(ret, two+board[i+1][j+1]+board[i+1][j+2]);
                        if (0 <= j-1) ret = Math.max(ret, two+board[i+1][j]+board[i+1][j-1]);
                    }
                }

                if (i+1 < r) {
                    two = board[i][j] + board[i+1][j];

                    if (i+2 < r) {
                        if (j+1 < c) ret = Math.max(ret, two+board[i+1][j+1]+board[i+2][j+1]);
                        if (0 <= j-1) ret = Math.max(ret, two+board[i+1][j-1]+board[i+2][j-1]);
                    }
                }
            }
        }

        return ret;
    }

    static int pink() {
        int ret = 0, three;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                three = 0;

                for (int k = 0; k < 3 && i+k < r; k++)
                    three += board[i+k][j];
                if (i+2 < r) {
                    if (j+1 < c) ret = Math.max(ret, three+board[i+1][j+1]);
                    if (0 <= j-1) ret = Math.max(ret, three+board[i+1][j-1]);
                }

                three = 0;
                for (int k = 0; k < 3 && j+k < c; k++)
                    three += board[i][j+k];
                if (j+2 < c) {
                    if (i+1 < r) ret = Math.max(ret, three+board[i+1][j+1]);
                    if (0 <= i-1) ret = Math.max(ret, three+board[i-1][j+1]);
                }
            }
        }

        return ret;
    }
}
