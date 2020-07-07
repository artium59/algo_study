import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[][] player;
    static int[] select = new int[9];
    static int n, ans;
    static boolean[] visited = new boolean[9];

    public static void main(String[] args) throws IOException {
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());

        player = new int[n][9];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++)
                player[i][j] = Integer.parseInt(st.nextToken());
        }

        select[3] = 0;
        visited[0] = true;
        permutation(0);

        System.out.print(ans);
    }

    static void permutation(int idx) {
        if (idx >= 9) {
            ans = Math.max(ans, play());
            return;
        }

        for (int i = 0; i < 9; i++) {
            if (visited[i]) continue;

            visited[i] = true;
            select[idx] = i;
            if (idx == 2) permutation(idx+2);
            else permutation(idx+1);
            visited[i] = false;
        }
    }

    static int play() {
        boolean[] base;
        int num = 0, out, ret = 0;

        for (int inning = 0; inning < n; inning++) {
            base = new boolean[4];
            out = 0;

            for ( ; out < 3; num++) {
                if (num == 9) num = 0;

                switch (player[inning][select[num]]) {
                    case 0: // out
                        out++;
                        break;
                    case 1:
                        if (base[3]) ret++;
                        base[3] = base[2];
                        base[2] = base[1];
                        base[1] = true;
                        break;
                    case 2:
                        if (base[3]) ret++;
                        if (base[2]) ret++;
                        base[3] = base[1];
                        base[2] = true;
                        base[1] = false;
                        break;
                    case 3:
                        if (base[3]) ret++;
                        if (base[2]) ret++;
                        if (base[1]) ret++;
                        base[3] = true;
                        base[2] = false;
                        base[1] = false;
                        break;
                    default: // homerun
                        for (int i = 1; i < 4; i++) {
                            if (base[i]) {
                                ret++;
                                base[i] = false;
                            }
                        }
                        ret++;
                }
            }
        }

        return ret;
    }
}
