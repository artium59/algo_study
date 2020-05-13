import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int n, k, a, b, c;
    static int[] arr;
    static Node[] tree = new Node[262144];

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());

        arr = new int[n];

        st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        init(1, 0, n-1);

        k = Integer.parseInt(bf.readLine());
        while (k-- > 0) {
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            if (a == 1) {
                b--;
                update(1, 0, n-1, b, c);
            }
            else {
                b--; c--;
                bw.write(query(1, 0, n-1, b, c, (a==3))+"\n");
            }
        }

        bw.flush();
    }

    static Node sum(Node a, Node b) {
        return new Node(a.odd+b.odd, a.even+b.even);
    }

    static Node init(int node, int start, int end) {
        if (start >= end) {
            if (arr[start] % 2 == 0) tree[node] = new Node(0, 1);
            else tree[node] = new Node(1, 0);

            return tree[node];
        }

        Node a = init(node*2, start, (start+end)/2);
        Node b = init(node*2+1, (start+end)/2+1, end);

        return tree[node] = new Node(a.odd+b.odd, a.even+b.even);
    }

    static Node update(int node, int start, int end, int loc, int num) {
        if (end < loc || loc < start) return tree[node];
        if (start >= end) {
            if (num % 2 == 0) tree[node] = new Node(0, 1);
            else tree[node] = new Node(1, 0);

            return tree[node];
        }

        Node a = update(node*2, start, (start+end)/2, loc, num);
        Node b = update(node*2+1, (start+end)/2+1, end, loc, num);

        return tree[node] = sum(a, b);
    }

    static int query(int node, int start, int end, int left, int right, boolean is_odd) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return is_odd ? tree[node].odd : tree[node].even;

        return query(node*2, start, (start+end)/2, left, right, is_odd) +
                query(node*2+1, (start+end)/2+1, end, left, right, is_odd);
    }
}

class Node {
    int odd=0, even=0;

    Node(int odd, int even) {
        this.odd = odd;
        this.even = even;
    }
}
