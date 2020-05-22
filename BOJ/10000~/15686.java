import java.io.*;
import java.util.*;

public class Main {
    static final int[] yrr = {-1,1,0,0}, xrr = {0,0,-1,1};
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Pair> chicken = new ArrayList<>();
    static int[][] city;
    static int n, m, homeCount, ans = Integer.MAX_VALUE;
    static boolean[][] visited;
    static boolean[] opened;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        city = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                city[i][j] = Integer.parseInt(st.nextToken());
                if (city[i][j] == 1)
                    homeCount++;
                else if (city[i][j] == 2)
                    chicken.add(new Pair(i, j));
            }
        }

        opened = new boolean[chicken.size()];
        comb(0, 0);
        System.out.print(ans);
    }

    static void comb(int idx, int cnt) {
        if (cnt == m) {
            ans = Math.min(ans, bfs());
            return;
        }

        if (idx >= chicken.size()) return;

        for (int i = idx; i < chicken.size(); i++) {
            opened[i] = true;
            comb(i+1, cnt+1);
            opened[i] = false;
        }
    }

    static int bfs() {
        int ret=0, dist, size, dy, dx, home = homeCount;
        Pair p;
        Queue<Pair> q = new ArrayDeque<>();

        visited = new boolean[n][n];
        for (int i = 0; i < chicken.size(); i++) {
            if (opened[i]) {
                q.add(chicken.get(i));
                visited[chicken.get(i).y][chicken.get(i).x] = true;
            }
        }

        for (dist = 1; !q.isEmpty() && home > 0; dist++) {
            size = q.size();
            for (int s = 0; s < size; s++) {
                p = q.poll();

                for (int i = 0; i < 4; i++) {
                    dy = p.y + yrr[i];
                    dx = p.x + xrr[i];

                    if (!boundaryCheck(dy, dx)) continue;
                    if (visited[dy][dx]) continue;
                    visited[dy][dx] = true;
                    q.add(new Pair(dy, dx));
                    if (city[dy][dx] == 1) {
                        ret += dist;
                        home--;
                    }
                }
            }
        }

        return ret;
    }

    static boolean boundaryCheck(int y, int x) {
        return 0 <= y && y < n && 0 <= x && x < n;
    }
}

class Pair {
    int y, x;
    Pair(int y, int x) {
        this.y = y;
        this.x = x;
    }
}
