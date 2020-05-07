import java.util.Scanner;

public class Main {
    static final int MAX = 1234567890;
    static int[][] W = new int[10][10];
    static int[][] cost = new int[10][1<<10];
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                W[i][j] = sc.nextInt();
        }

        System.out.print(TSP(0, 1));

    }

    static int TSP(int cur, int visited) {
        if (visited == (1<<n)-1) return W[cur][0] == 0 ? MAX : W[cur][0];

        if (cost[cur][visited] != 0) return cost[cur][visited];
        cost[cur][visited] = MAX;

        for (int i = 0; i < n; i++) {
            if (((1<<i) & visited) != 0 || W[cur][i] == 0) continue;

            cost[cur][visited] = Math.min(cost[cur][visited], W[cur][i]+TSP(i, (visited | (1<<i))));
        }

        return cost[cur][visited];
    }
}
