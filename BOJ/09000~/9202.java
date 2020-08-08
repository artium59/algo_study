import java.io.*;
import java.util.*;

public class Main {
    static final int[] xrr = {-1,-1,-1,0,0,1,1,1}, yrr = {-1,0,1,-1,1,-1,0,1}, score={0,0,0,1,1,2,3,5,11};
    static Set<String> check;
    static int w, b, sum, cnt;
    static char[][] board = new char[4][4];
    static boolean[][] visited = new boolean[4][4];
    static String str;
    static TrieNode head = new TrieNode();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        w = Integer.parseInt(br.readLine());
        for (int i = 0; i < w; i++) {
            str = br.readLine();
            head.insert(str, 0);
        }
        br.readLine();

        b = Integer.parseInt(br.readLine());
        while (b-- > 0) {
            for (int i = 0; i < 4; i++)
                board[i] = br.readLine().toCharArray();
            if (b > 0) br.readLine();

            str = "";
            sum = cnt = 0;
            check = new HashSet<>();

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (head.child[board[i][j]-'A'] == null) continue;

                    visited[i][j] = true;
                    dfs(head.child[board[i][j]-'A'], i, j, new StringBuilder().append(board[i][j]));
                    visited[i][j] = false;
                }
            }

            sb.append(sum).append(' ').append(str).append(' ').append(cnt).append('\n');
        }

        System.out.print(sb.toString());
    }

    private static void dfs(TrieNode cur, int y, int x, StringBuilder word) {
        if (word.length() > 8) return;

        if (cur.isEnd && !check.contains(word.toString())) {
            check.add(word.toString());
            addScore(word.toString());
        }

        for (int k = 0; k < 8; k++) {
            int dy = y + yrr[k];
            int dx = x + xrr[k];

            if (0<=dy&&dy<4 && 0<=dx&&dx<4) {
                if (visited[dy][dx]) continue;
                if (cur.child[board[dy][dx]-'A'] == null) continue;

                visited[dy][dx] = true;
                dfs(cur.child[board[dy][dx]-'A'], dy, dx, new StringBuilder(word).append(board[dy][dx]));
                visited[dy][dx] = false;
            }
        }
    }

    private static void addScore(String word) {
        ++cnt;
        sum += score[word.length()];
        if (str.length() < word.length())
            str = word;
        else if (str.length() == word.length()) {
            if (str.compareTo(word) > 0)
                str = word;
        }
    }
}

class TrieNode {
    boolean isEnd;
    TrieNode[] child;

    public TrieNode() {
        this.isEnd = false;
        this.child = new TrieNode[26];
    }

    public void insert(String s, int idx) {
        if (idx >= s.length()) {
            this.isEnd = true;
            return;
        }

        if (this.child[s.charAt(idx)-'A'] == null) {
            this.child[s.charAt(idx)-'A'] = new TrieNode();
        }

        this.child[s.charAt(idx)-'A'].insert(s, idx+1);
    }
}
