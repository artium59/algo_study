import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static int[] count;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int big = 0;

        graph = new ArrayList[n+1];
        for (int i = 1; i <= n; i++)
            graph[i] = new ArrayList<>();
        count = new int[n+1];
        visited = new boolean[n+1];

        while (m-- > 0) {
            st = new StringTokenizer(bf.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a].add(b);
        }

        for (int i = 1; i <= n; i++) {
            visited = new boolean[n+1];
            dfs(i);
        }

        for (int i = 1; i <= n; i++)
            big = Math.max(big, count[i]);

        for (int i = 1; i <= n; i++) {
            if (count[i] == big)
                bw.write(i+" ");
        }

        bw.flush();
    }

    static void dfs(int cur) {
        visited[cur] = true;
        for (int g : graph[cur]) {
            if (visited[g]) continue;
            count[g]++;
            dfs(g);
        }
    }
}
