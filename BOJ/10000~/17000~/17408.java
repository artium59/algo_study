import java.io.*;
import java.util.*;

public class Main {
    static final Node MIN = new Node(-1, -1);
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] arr;
    static int n, m, a, b, c;
    static Node[] tree = new Node[263144];
    static Node tmp;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(bf.readLine());

        arr = new int[n];
        StringTokenizer st = new StringTokenizer(bf.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        init(1, 0, n-1);

        m = Integer.parseInt(bf.readLine());
        while (m-- > 0) {
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            if (a == 1)
                update(1, 0, n-1, b-1, c);
            else {
                tmp = query(1, 0, n-1, b-1, c-1);
                bw.write((tmp.x+tmp.y)+"\n");
            }
        }

        bw.flush();
    }

    static Node select(Node a, Node b) {
        int[] tmp = {a.x, a.y, b.x, b.y};
        Arrays.sort(tmp);

        return new Node(tmp[2], tmp[3]);
    }

    static Node init(int node, int start, int end) {
        if (start >= end)
            return tree[node] = new Node(arr[start], 0);

        Node a = init(node*2, start, (start+end)/2);
        Node b = init(node*2+1, (start+end)/2+1, end);

        return tree[node] = select(a, b);
    }

    static Node update(int node, int start, int end, int loc, int num) {
        if (end < loc || loc < start) return tree[node];
        if (start >= end) return tree[node] = new Node(num, 0);

        Node a = update(node*2, start, (start+end)/2, loc, num);
        Node b = update(node*2+1, (start+end)/2+1, end, loc, num);

        return tree[node] = select(a, b);
    }

    static Node query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return MIN;
        if (left <= start && end <= right) return tree[node];
        if (start >= end) return tree[node];

        Node a = query(node*2, start, (start+end)/2, left, right);
        Node b = query(node*2+1, (start+end)/2+1, end, left, right);

        return select(a, b);
    }
}

class Node {
    int x, y;

    Node(int a, int b) {
        this.y = a;
        this.x = b;
    }
}
