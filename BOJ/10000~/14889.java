import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static int[][] arr;
    static int n, ans = 1234567890;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        n = Integer.parseInt(bf.readLine());

        arr = new int[n][n];
        visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 0; j < n; j++)
                arr[i][j] = Integer.parseInt(st.nextToken());
        }

        comb(0, 0);
        System.out.print(ans);
    }

    static void comb(int idx, int cnt) {
        if (cnt >= n/2) {
            ans = Math.min(ans, sum());
            return;
        }

        for (int i = idx; i < n; i++) {
            visited[i] = true;
            comb(i+1, cnt+1);
            visited[i] = false;
        }
    }

    static int sum() {
        int a = 0, b = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (visited[i] && visited[j])
                    a += arr[i][j] + arr[j][i];
                else if (!visited[i] && !visited[j])
                    b += arr[i][j] + arr[j][i];
            }
        }

        return Math.abs(a-b);
    }
}
