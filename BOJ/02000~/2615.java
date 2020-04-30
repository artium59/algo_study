import java.util.Scanner;

public class Main {
    static int[][][] board = new int[19][19][5];

    public static void main(String[] args) {
        int winner=0, x=0, y=0;
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++)
                board[i][j][0] = sc.nextInt();
        }

        for (int j = 0; j < 19; j++) {
            for (int i = 0; i < 19; i++) {
                if (board[i][j][0] != 0) {
                    if (check(i, j)) {
                        y = i+1; x = j+1;
                        winner = board[i][j][0];
                        break;
                    }
                    board[i][j][0] = 0;
                }
            }

            if (winner != 0) break;
        }

        System.out.println(winner);
        if (winner != 0) System.out.println(y+" "+x);
    }

    static boolean check(int y, int x) {
        int color = board[y][x][0];
        int cnt = 1;
        // 1. row
        for (int i = 0; y+i < 19 && board[y+i][x][1] == 0; i++) {
            if (board[y+i][x][0] != color) break;
            board[y+i][x][1] = cnt++;
        }
        if (cnt == 6) return true;

        cnt = 1;
        // 2. column
        for (int i = 0; x+i < 19 && board[y][x+i][2] == 0; i++) {
            if (board[y][x+i][0] != color) break;
            board[y][x+i][2] = cnt++;
        }
        if (cnt == 6) return true;

        cnt = 1;
        // 3. right up diagonal
        for (int i = 0; y-i >= 0 && x+i < 19 && board[y-i][x+i][3] == 0; i++) {
            if (board[y-i][x+i][0] != color) break;
            board[y-i][x+i][3] = cnt++;
        }
        if (cnt == 6) return true;

        cnt = 1;
        // 4. right down diagonal
        for (int i = 0; y+i < 19 && x+i < 19 && board[y+i][x+i][4] == 0; i++) {
            if (board[y+i][x+i][0] != color) break;
            board[y+i][x+i][4] = cnt++;
        }
        if (cnt == 6) return true;

        return false;
    }
}
