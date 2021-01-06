import java.io.*;
import java.util.*;

public class Main {
    static int[] arr, ans, tree = new int[262144];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        ans = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        init(1, 0, n-1);
        for (int i = n-1; i >= 0; i--) {
            int loc = query(1, 0, n-1, arr[i]);
            ans[loc] = i+1;
            update(1, 0, n-1, loc);
        }

        for (int i = 0; i < n; i++)
            sb.append(ans[i]).append(' ');
        System.out.print(sb.toString());
    }

    private static int init(int node, int start, int end) {
        if (start >= end) return tree[node] = 1;

        return tree[node] = init(node*2, start, (start+end)/2) +
                            init(node*2+1, (start+end)/2+1, end);
    }

    private static void update(int node, int start, int end, int loc) {
        if (loc < start || end < loc) return;

        tree[node]--;
        if (start >= end) return;

        update(node*2, start, (start+end)/2, loc);
        update(node*2+1, (start+end)/2+1, end, loc);
    }

    private static int query(int node, int start, int end, int cnt) {
        if (start >= end) return start;

        int mid = (start + end) / 2;
        if (tree[node*2+1] > cnt) return query(node*2+1, mid+1, end, cnt);
        else return query(node*2, start, mid, cnt-tree[node*2+1]);
    }
}
