import java.io.*;
import java.util.*;

public class Main {
    static HashMap<Integer, Integer> pieces = new HashMap<>();
    static int[] A, B;
    static int t, n ,m, tmp;
    static long ans;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        t = sc.nextInt();
        m = sc.nextInt();
        n = sc.nextInt();

        A = new int[m];
        B = new int[n];

        for (int i = 0; i < m; i++)
            A[i] = sc.nextInt();
        for (int i = 0; i < n; i++)
            B[i] = sc.nextInt();

        for (int size = 1; size < m; size++) {
            for (int start = 0; start < m; start++) {
                tmp = 0;
                for (int j = 0; j < size; j++)
                    tmp += A[(start+j) % m];
                pieces.put(tmp, pieces.containsKey(tmp) ? pieces.get(tmp)+1 : 1);
            }
        }

        tmp = 0;
        for (int i = 0; i < m; i++)
            tmp += A[i];
        pieces.put(tmp, pieces.containsKey(tmp) ? pieces.get(tmp)+1 : 1);

        for (int size = 1; size < n; size++) {
            for (int start = 0; start < n; start++) {
                tmp = 0;
                for (int j = 0; j < size; j++)
                    tmp += B[(start+j) % n];
                if (tmp == t) ans++;
                if (pieces.containsKey(t-tmp))
                    ans += pieces.get(t-tmp);
            }
        }

        tmp = 0;
        for (int i = 0; i < n; i++)
            tmp += B[i];
        if (tmp == t) ans++;
        if (pieces.containsKey(t-tmp))
            ans += pieces.get(t-tmp);

        if (pieces.containsKey(t))
            ans += pieces.get(t);

        System.out.print(ans);
    }
}
