import java.io.*;
import java.util.*;

public class Main {
    static PriorityQueue<Edge> pq = new PriorityQueue<>();
    static int[] parent, rank;
    static int v, e, a, b, c;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        v = Integer.parseInt(st.nextToken());
        e = Integer.parseInt(st.nextToken());

        parent = new int[v];
        rank = new int[v];

        for (int i = 0; i < v; i++)
            parent[i] = i;

        while (e-- > 0) {
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()); --a;
            b = Integer.parseInt(st.nextToken()); --b;
            c = Integer.parseInt(st.nextToken());

            pq.add(new Edge(a, b, c));
        }

        int cnt = 1, ans = 0;
        while (!pq.isEmpty() && cnt < v) {
            Edge edge = pq.poll();

            if (find(edge.start) == find(edge.end)) continue;

            union(edge.start, edge.end);
            ans += edge.cost;
            cnt++;
        }

        System.out.print(ans);
    }

    private static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (rank[pa] > rank[pb])
            parent[pb] = pa;
        else {
            parent[pa] = pb;
            if (rank[pa] == rank[pb])
                rank[pb]++;
        }
    }

    private static int find(int a) {
        if (parent[a] == a) return a;
        else return parent[a] = find(parent[a]);
    }
}

class Edge implements Comparable<Edge> {
    int start, end, cost;

    Edge(int start, int end, int cost) {
        this.start = start;
        this.end = end;
        this.cost = cost;
    }

    @Override
    public int compareTo(Edge o) {
        return Integer.compare(this.cost, o.cost);
    }
}
