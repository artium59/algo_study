import java.io.*;
import java.util.*;

public class Main {
    static int[] arr, tree;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());

        arr = new int[n];
        tree = new int[524288];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        init(1, 0, n-1);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int cur = Integer.parseInt(st.nextToken());
            int q = query(1, 0, n-1, cur);

            sb.append(q+1).append(' ');
            update(1, 0, n-1, q);
        }

        System.out.print(sb.toString());
    }

    private static int init(int node, int start, int end) {
        if (start >= end) return tree[node] = arr[start];

        return tree[node] = init(node*2, start, (start+end)/2) +
                init(node*2+1, (start+end)/2+1, end);
    }

    private static void update(int node, int start, int end, int loc) {
        if (end < loc || loc < start) return;

        tree[node] -= arr[loc];
        if (start >= end) return;

        update(node*2, start, (start+end)/2, loc);
        update(node*2+1, (start+end)/2 + 1, end, loc);
    }

    private static int query(int node, int start, int end, int num) {
        if (start >= end) return start;

        if (tree[node*2] >= num)
            return query(node*2, start, (start+end)/2, num);
        else
            return query(node*2+1, (start+end)/2+1, end, num-tree[node*2]);
    }
}
