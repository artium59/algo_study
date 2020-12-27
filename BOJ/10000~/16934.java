import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        TrieNode root = new TrieNode();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String nickname = br.readLine();
            root.insert(nickname, 0, sb, false);
        }

        System.out.print(sb.toString());
    }
}

class TrieNode {
    int count;
    boolean isEnd;
    TrieNode[] child;

    public TrieNode() {
        this.count = 0;
        this.isEnd = false;
        this.child = new TrieNode[26];
    }

    public void insert(String s, int idx, StringBuilder sb, boolean isAppending) {
        if (idx >= s.length()) {
            this.count++;
            this.isEnd = true;
            if (!isAppending) {
                if (this.count > 1)
                    sb.append(this.count);
                sb.append('\n');
            }
            return;
        }

        if (!isAppending)
            sb.append(s.charAt(idx));

        if (this.child[s.charAt(idx)-'a'] == null) {
            this.child[s.charAt(idx)-'a'] = new TrieNode();
            if (!isAppending) {
                sb.append('\n');
                isAppending = true;
            }
        }

        this.child[s.charAt(idx)-'a'].insert(s, idx+1, sb, isAppending);
    }
}
