import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1000000007;
    static final int end = 200000-1;
    static long[] sumTree = new long[524288], cntTree = new long[524288];
    static long ans = 1;
    static int n, t;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            t = Integer.parseInt(br.readLine());

            if (i > 0) {
                ans = ans * ((query(sumTree, 1, 0, end, t+1, end) -
                        t * query(cntTree, 1, 0, end, t+1, end) +
                        t * query(cntTree, 1, 0, end, 0, t-1)
                        - query(sumTree, 1, 0, end, 0, t-1)) % MOD) % MOD;
            }

            updateCntTree(1, 0, end, t);
            updateSumTree(1, 0, end, t);
        }

        System.out.print(ans);
    }

    private static void updateSumTree(int node, int start, int end, int loc) {
        if (loc < start || end < loc) return;
        if (start <= loc && loc <= end) sumTree[node] += loc;
        if (start >= end) return;

        updateSumTree(node*2, start, (start+end)/2, loc);
        updateSumTree(node*2+1, (start+end)/2+1, end, loc);
    }

    private static void updateCntTree(int node, int start, int end, int loc) {
        if (loc < start || end < loc) return;
        if (start <= loc && loc <= end) cntTree[node]++;
        if (start >= end) return;

        updateCntTree(node*2, start, (start+end)/2, loc);
        updateCntTree(node*2+1, (start+end)/2+1, end, loc);
    }

    private static long query(long[] tree, int node, int start, int end, int left, int right) {
        if (left > right) return 0;
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];

        return query(tree, node*2, start, (start+end)/2, left, right) +
                query(tree, node*2+1, (start+end)/2+1, end, left, right);
    }
}
