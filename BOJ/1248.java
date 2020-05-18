import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static String str;
    static char[][] arr;
    static int[] ans;
    static int n, m;
    static boolean check;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(bf.readLine());
        str = bf.readLine();

        arr = new char[n][n];
        ans = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++)
                arr[i][j] = str.charAt(m++);
        }

        find(0);
        for (int a : ans)
            System.out.print(a+" ");
    }

    static void find(int idx) {
        if (idx >= n) {
            check = true;
            return;
        }

        if (arr[idx][idx] == '+') {
            for (int i = 1; i < 11; i++) {
                if (check) return;
                ans[idx] = i;
                if (!verify(idx)) continue;
                find(idx+1);
            }
        }
        else if (arr[idx][idx] == '-') {
            for (int i = -10; i < 0; i++) {
                if (check) return;
                ans[idx] = i;
                if (!verify(idx)) continue;
                find(idx+1);
            }
        }
        else {
            if (check) return;
            ans[idx] = 0;
            find(idx+1);
        }
    }

    static boolean verify(int idx) {
        int sum = ans[idx];

        for (int i = idx-1; i >= 0; i--) {
            sum += ans[i];
            if (arr[i][idx] == '+') {
                if (sum <= 0)
                    return false;
            }
            else if (arr[i][idx] == '-') {
                if (sum >= 0)
                    return false;
            }
            else {
                if (sum != 0)
                    return false;
            }
        }

        return true;
    }
}
