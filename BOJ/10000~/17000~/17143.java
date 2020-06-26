import java.io.*;
import java.util.*;

public class Main {
    static Shark[][] sea;
    static int r, c, m, x, y, s, d, z, ans;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        sea = new Shark[r+1][c+1];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());

            y = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());

            sea[y][x] = new Shark(s, d, z);
        }

        for (int z = 1; z <= c; z++) {
            fishing(z);
            move();
        }

        System.out.print(ans);
    }

    private static void move() {
        int cnt;
        Shark[][] ret = new Shark[r+1][c+1];

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (sea[i][j] == null) continue;

                y = i; x = j;
                d = sea[i][j].dir;
                cnt = sea[i][j].speed;

                while (cnt > 0) {
                    switch (d) {
                        case 1:
                            if (y-cnt >= 1) {
                                y -= cnt;
                                cnt = 0;
                            }
                            else {
                                cnt -= y-1;
                                y = 1;
                                d = 2;
                            }
                            break;
                        case 2:
                            if (y+cnt <= r) {
                                y += cnt;
                                cnt = 0;
                            }
                            else {
                                cnt -= r-y;
                                y = r;
                                d = 1;
                            }
                            break;
                        case 3:
                            if (x+cnt <= c) {
                                x += cnt;
                                cnt = 0;
                            }
                            else {
                                cnt -= c-x;
                                x = c;
                                d = 4;
                            }
                            break;
                        case 4:
                            if (x-cnt >= 1) {
                                x -= cnt;
                                cnt = 0;
                            }
                            else {
                                cnt -= x-1;
                                x = 1;
                                d = 3;
                            }
                            break;
                    }
                }

                if (ret[y][x] != null) {
                    if (ret[y][x].bulk < sea[i][j].bulk) {
                        ret[y][x].speed = sea[i][j].speed;
                        ret[y][x].dir = d;
                        ret[y][x].bulk = sea[i][j].bulk;
                    }
                }
                else
                    ret[y][x] = new Shark(sea[i][j].speed, d, sea[i][j].bulk);
            }
        }

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++)
                sea[i][j] = ret[i][j];
        }
    }

    private static void fishing(int j) {
        for (int i = 1; i <= r; i++) {
            if (sea[i][j] == null) continue;

            ans += sea[i][j].bulk;
            sea[i][j] = null;
            break;
        }
    }
}

class Shark {
    int speed, dir, bulk;

    Shark(int speed, int dir, int bulk) {
        this.speed = speed;
        this.dir = dir;
        this.bulk = bulk;
    }
}
