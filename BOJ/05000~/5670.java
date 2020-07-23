import java.io.*;

public class Main {
    static int n;
    static double ans;
    static String[] str;
    static TrieNode head;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;

        while ((line = br.readLine()) != null) {
            n = Integer.parseInt(line);
            str = new String[n];
            head = new TrieNode();

            for (int i = 0; i < n; i++) {
                str[i] = br.readLine();
                head.insert(str[i], 0);
            }

            ans = 0;
            for (int i = 0; i < n; i++)
                ans += find(str[i]);

            System.out.print(String.format("%.2f\n", ans/n));
        }
    }

    private static double find(String s) {
        int idx = 1;
        double cnt = 1;
        TrieNode cur = head.child[s.charAt(0)-'a'];

        while (cur != null && idx < s.length()) {
            if (cur.childCnt > 1 || (cur.isEnd && cur.childCnt > 0)) ++cnt;
            cur = cur.child[s.charAt(idx++)-'a'];
        }

        return cnt;
    }
}

class TrieNode {
    int childCnt;
    boolean isEnd;
    TrieNode[] child;

    public TrieNode() {
        childCnt = 0;
        this.isEnd = false;
        this.child = new TrieNode[26];
    }

    public void insert(String s, int idx) {
        if (idx >= s.length()) {
            this.isEnd = true;
            return;
        }

        if (this.child[s.charAt(idx)-'a'] == null) {
            this.childCnt++;
            this.child[s.charAt(idx)-'a'] = new TrieNode();
        }

        this.child[s.charAt(idx)-'a'].insert(s, idx+1);
    }
}
