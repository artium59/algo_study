import java.io.*;
import java.util.*;

public class Main {
    static TrieNode root = new TrieNode();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), len;
        int[] arr;

        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());

            len = Integer.parseInt(st.nextToken());
            arr = new int[len];
            for (int i = 0; i < len; i++)
                arr[i] = Integer.parseInt(st.nextToken());
            root.insert(arr, 0);
        }
        while (n-- > 0) {
            st = new StringTokenizer(br.readLine());

            len = Integer.parseInt(st.nextToken());
            arr = new int[len];
            for (int i = 0; i < len; i++)
                arr[i] = Integer.parseInt(st.nextToken());
            sb.append(root.find(arr, 0)).append('\n');
        }

        System.out.print(sb.toString());
    }
}

class TrieNode {
    int passCount;
    int endCount;
    TrieNode[] children;

    public TrieNode() {
        this.passCount = 0;
        this.endCount = 0;
        this.children = new TrieNode[2];
    }

    int find(int[] arr, int idx) {
        if (idx >= arr.length)
            return this.passCount + this.endCount;

        if (this.children[arr[idx]] == null)
            return this.endCount;
        else
            return this.endCount + this.children[arr[idx]].find(arr, idx+1);
    }

    void insert(int[] arr, int idx) {
        ++passCount;
        if (idx >= arr.length) {
            --passCount;
            ++endCount;
            return;
        }

        if (this.children[arr[idx]] == null)
            this.children[arr[idx]] = new TrieNode();

        this.children[arr[idx]].insert(arr, idx+1);
    }
}
