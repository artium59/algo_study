import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static String str;
    static int[] words;
    static int n, k, ans;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        words = new int[n];
        for (int i = 0; i < n; i++) {
            str = bf.readLine();
            ans = 0;
            for (int j = 4; j < str.length()-4; j++)
                ans |= (1<<(str.charAt(j)-'a'));

            words[i] = ans;
        }

        ans = 0;
        if (k > 4)
            select(1, 5, 532741);
        System.out.print(ans);
    }

    static void select(int idx, int cnt, int visited) {
        if (cnt == k) {
            ans = Math.max(ans, reading(visited));
            return;
        }

        if (idx == 26) return;

        for (int i = idx; i < 26; i++) {
            if ((visited & (1<<i)) == 0)
                select(i+1, cnt+1, visited|(1<<i));
        }
    }

    static int reading(int visited) {
        int ret = 0;

        for (int word : words) {
            if ((word & visited) == word) ret++;
        }

        return ret;
    }
}
