import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        int[][] bus = new int[n][n];

        while (m-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()); --a;
            int b = Integer.parseInt(st.nextToken()); --b;
            int c = Integer.parseInt(st.nextToken());

            if (bus[a][b] == 0)
                bus[a][b] = c;
            else
                bus[a][b] = Math.min(bus[a][b], c);
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (bus[i][k] == 0 || bus[k][j] == 0) continue;

                    if (bus[i][j] == 0)
                        bus[i][j] = bus[i][k] + bus[k][j];
                    else
                        bus[i][j] = Math.min(bus[i][j], bus[i][k] + bus[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) bus[i][j] = 0;
                bw.write(bus[i][j]+" ");
            }
            bw.write("\n");
        }

        bw.flush();
    }
}
