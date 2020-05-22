import java.io.*;
import java.util.*;

public class Main {
    static final TrieNode root = new TrieNode();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String str;
    static int n;
    static boolean[] visited = new boolean[100];
    static boolean check = true;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            str = br.readLine();
            insert();
        }
        for (int i = 0; i < 3; i++) {
            str = br.readLine();
            check = find(0, 0, i == 1 ? 7 : 5);
            if (!check) break;
        }

        System.out.print(check ? "haiku" : "come back next year");
    }

    static void insert() {
        TrieNode cur = root;

        for (int i = 0; i < str.length(); i++) {
            if (cur.next[str.charAt(i)-'a'] == null)
                cur.next[str.charAt(i)-'a'] = new TrieNode();
            cur = cur.next[str.charAt(i)-'a'];
        }

        cur.isTerminal = true;
    }

    static boolean find(int idx, int cnt, int divide) {
        if (idx >= str.length())
            return cnt == divide;

        if (cnt >= divide) return false;

        TrieNode cur = root;
        boolean ret = false;

        for (int i = idx; i < str.length(); i++) {
            if (ret) break;
            if (str.charAt(i) == ' ') break;
            if (cur.next[str.charAt(i)-'a'] == null) break;

            cur = cur.next[str.charAt(i)-'a'];

            if (cur.isTerminal) {
                if (visited[i]) continue;

                visited[i] = true;
                if (i < str.length()-1 && str.charAt(i+1) == ' ')
                    ret = find(i+2, cnt+1, divide);
                else
                    ret = find(i+1, cnt+1, divide);
                visited[i] = false;
            }
        }

        return ret;
    }
}

class TrieNode {
    TrieNode[] next = new TrieNode[26];
    boolean isTerminal;

    TrieNode() {
        isTerminal = false;
    }
}
