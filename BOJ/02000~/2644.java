import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Integer>[] lst;
    static boolean[] visited;
    static int n, m, x, y, a, b, ans=-1;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());
        a = Integer.parseInt(st.nextToken()); --a;
        b = Integer.parseInt(st.nextToken()); --b;

        lst = new ArrayList[n];
        visited = new boolean[n];

        m = Integer.parseInt(bf.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(bf.readLine());
            x = Integer.parseInt(st.nextToken()); --x;
            y = Integer.parseInt(st.nextToken()); --y;

            if (lst[x] == null) lst[x] = new ArrayList<>();
            if (lst[y] == null) lst[y] = new ArrayList<>();

            lst[x].add(y);
            lst[y].add(x);
        }

        visited[a] = true;
        dfs(a, 0);
        System.out.print(ans);
    }

    static void dfs(int cur, int level) {
        if (cur == b) {
            ans = level; return;
        }

        for (int l : lst[cur]) {
            if (visited[l]) continue;

            visited[l] = true;
            dfs(l, level+1);
        }
    }
}
