import java.io.*;
import java.util.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int m = Integer.parseInt(br.readLine());
        int n = Integer.parseInt(br.readLine());
        List<Integer>[] list = new ArrayList[m*n + 1];

        StringTokenizer st;
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                if (list[i*j] == null)
                    list[i*j] = new ArrayList<Integer>();

                list[i*j].add(Integer.parseInt(st.nextToken()));
            }
        }

        System.out.print(find(list, m, n));
    }

    private static String find(List<Integer>[] list, int m, int n) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[list.length];

        q.add(1);
        while (!q.isEmpty()) {
            int cur = q.poll();

            if (cur == m*n) return "yes";
            if (cur >= list.length) continue;
            if (list[cur] == null) continue;

            for (int i : list[cur]) {
                if (i >= visited.length) continue;
                if (visited[i]) continue;

                visited[i] = true;
                q.add(i);
            }
        }

        return "no";
    }
}
