import java.io.*;
import java.util.*;

public class Main {
    static final int[] xrr = {0,0,-1,1}, yrr = {-1,1,0,0};
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static ArrayList<Integer>[] adj;
    static ArrayList<Integer> ans = new ArrayList<>();
    static boolean[] visited;
    static int n, m, k, x, a, b;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n+1];
        visited = new boolean[n+1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            if (adj[a] == null) adj[a] = new ArrayList<>();
            if (adj[b] == null) adj[b] = new ArrayList<>();

            adj[a].add(b);
        }
        bfs();

        if (ans.size() == 0)
            System.out.print(-1);
        else {
            Collections.sort(ans);
            for (int a : ans)
                bw.write(a+"\n");
            bw.flush();
        }
    }

    static void bfs() {
        int size;
        boolean check = false;
        Queue<Integer> q = new ArrayDeque<>();

        q.add(x);
        visited[x] = true;
        for (int cnt = 0; cnt < k && !q.isEmpty(); cnt++) {
            size = q.size();
            for (int s = 0; s < size; s++) {
                x = q.poll();

                for (int ad : adj[x]) {
                    if (visited[ad]) continue;

                    visited[ad] = true;
                    q.add(ad);
                }
            }

            if (cnt == k-1) check = true;
        }

        while (!q.isEmpty() && check)
            ans.add(q.poll());
    }
}
