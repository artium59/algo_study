import java.io.*;
import java.util.*;

public class Main {
    static int[][] arr;
    static int r, c, t, y, ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());

        arr = new int[r][c];
        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < c; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] == -1)
                    y = i;
            }
        }

        for (int i = 0; i < t; i++) {
            spread();
            cleaner();
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                ans += arr[i][j];
        }

        System.out.print(ans+2);
    }

    private static void cleaner() {
        for (int i = y-2; i > 0; i--)
            arr[i][0] = arr[i-1][0];
        for (int j = 0; j < c-1; j++)
            arr[0][j] = arr[0][j+1];
        for (int i = 0; i < y-1; i++)
            arr[i][c-1] = arr[i+1][c-1];
        for (int j = c-1; j > 1; j--)
            arr[y-1][j] = arr[y-1][j-1];
        arr[y-1][1] = 0;

        for (int i = y+1; i < r-1; i++)
            arr[i][0] = arr[i+1][0];
        for (int j = 0; j < c-1; j++)
            arr[r-1][j] = arr[r-1][j+1];
        for (int i = r-1; i > y; i--)
            arr[i][c-1] = arr[i-1][c-1];
        for (int j = c-1; j > 1; j--)
            arr[y][j] = arr[y][j-1];
        arr[y][1] = 0;
    }

    private static void spread() {
        int[][] ret = new int[r][c];
        int sum;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] <= 0) continue;

                sum = 0;
                if (i-1 >= 0 && arr[i-1][j] != -1) {
                    ret[i-1][j] += arr[i][j] / 5;
                    sum += arr[i][j] / 5;
                }

                if (i+1 < r && arr[i+1][j] != -1) {
                    ret[i+1][j] += arr[i][j] / 5;
                    sum += arr[i][j] / 5;
                }

                if (j-1 >= 0 && arr[i][j-1] != -1) {
                    ret[i][j-1] += arr[i][j] / 5;
                    sum += arr[i][j] / 5;
                }

                if (j+1 < c && arr[i][j+1] != -1) {
                    ret[i][j+1] += arr[i][j] / 5;
                    sum += arr[i][j] / 5;
                }

                ret[i][j] += arr[i][j] - sum;
            }
        }

        ret[y-1][0] = ret[y][0] = -1;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                arr[i][j] = ret[i][j];
        }
    }
}
