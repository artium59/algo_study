import java.io.*;
import java.util.*;

public class Main {
    static final int MAX = 262144;
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, l, r;
    static Pair[] arr;
    static int[] tree = new int[MAX];

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());
        arr = new Pair[n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            arr[i] = new Pair(Integer.parseInt(st.nextToken()), i);
        }

        init(1, 0, n-1);
        Arrays.sort(arr);

        l=0; r = n-1;
        while (l <= r) {
            bw.write(search(1, 0, n-1, 0, arr[l].loc-1)+"\n");
            query(1, 0, n-1, arr[l].loc); l++;
            if (l > r) break;
            bw.write(search(1, 0, n-1, arr[r].loc+1, n-1)+"\n");
            query(1, 0, n-1, arr[r].loc); r--;
        }
        bw.flush();
    }

    static int init(int node, int start, int end) {
        if (start >= end) return tree[node] = 1;

        return tree[node] = init(node*2, start, (start+end)/2) +
                            init(node*2+1, (start+end)/2+1, end);
    }

    static int search(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];

        return search(node*2, start, (start+end)/2, left, right) +
                search(node*2+1, (start+end)/2+1, end, left, right);
    }

    static void query(int node, int start, int end, int loc) {
        if (loc < start || end < loc) return;
        tree[node]--;
        if (start >= end) return;

        query(node*2, start, (start+end)/2, loc);
        query(node*2+1, (start+end)/2+1, end, loc);
    }
}

class Pair implements Comparable<Pair> {
    int num, loc;

    Pair(int a, int b) {
        this.num = a;
        this.loc = b;
    }

    @Override
    public int compareTo(Pair other) {
        if (num < other.num) return -1;
        else return 1;
    }
}
