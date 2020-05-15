import java.io.*;
import java.util.*;

public class Main {
    static final int[] xrr = {0,0,-1,1}, yrr = {-1,1,0,0};
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static Queue<Tuple> q = new ArrayDeque<>(), vol = new ArrayDeque<>();
    static Tuple[] volcano;
    static boolean[][] visited;
    static int[][] height;
    static int m, n, v, x, y, a, b, c, max_height, min_hour;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(bf.readLine());
        y = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());

        visited = new boolean[m+1][n+1];
        height = new int[m+1][n+1];
        volcano = new Tuple[v];

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(bf.readLine());
            for (int j = 1; j <= n; j++)
                height[i][j] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < v; i++) {
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());

            height[a][b] = -5;
            volcano[i] = new Tuple(a, b, c);
        }
        Arrays.sort(volcano);

        bfs();
        System.out.print(max_height + " " + min_hour);
    }

    static void bfs() {
        int start = 0, dx, dy, size;
        Tuple t;

        q.add(new Tuple(y, x, 0));
        visited[y][x] = true;
        max_height = height[y][x];
        min_hour = 0;

        for (int hour = 0 ; ; hour++) {
            for (int k = start; k < v; k++) {
                if (volcano[k].count > hour) break;

                vol.add(volcano[k]);
                start = k;
            }

            size = vol.size();
            for (int k = 0; k < size; k++) {
                t = vol.poll();

                for (int i = 0; i < 4; i++) {
                    dy = t.y + yrr[i];
                    dx = t.x + xrr[i];

                    if (boundaryCheck(dy, dx) && height[dy][dx] != -1) {
                        height[dy][dx] = -1;
                        vol.add(new Tuple(dy, dx, 0));
                    }
                }
            }

            size = q.size();
            if (size == 0) break;
            for (int k = 0; k < size; k++) {
                t = q.poll();

                for (int i = 0; i < 4; i++) {
                    dy = t.y + yrr[i];
                    dx = t.x + xrr[i];

                    if (boundaryCheck(dy, dx) && height[dy][dx] >= 0 && !visited[dy][dx]) {
                        visited[dy][dx] = true;
                        q.add(new Tuple(dy, dx, 0));

                        if (max_height < height[dy][dx]) {
                            max_height = height[dy][dx];
                            min_hour = hour+1;
                        }
                    }
                }
            }
        }
    }

    static boolean boundaryCheck(int y, int x) {
        return 0 < y && y <= m && 0 < x && x <= n;
    }
}

class Tuple implements Comparable<Tuple> {
    int x, y, count;

    Tuple(int y, int x, int count) {
        this.y = y;
        this.x = x;
        this.count = count;
    }

    @Override
    public int compareTo(Tuple other) {
        return Integer.compare(count, other.count);
    }
}
