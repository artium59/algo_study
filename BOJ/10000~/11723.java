import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] arr = new int[11];
    static int[] operator = new int[4];
    static int s = 0, m, t;
    static String str;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();

        while (m-- > 0) {
            str = sc.next();
            if (!str.equals("all") && !str.equals("empty")) t = sc.nextInt();

            switch (str) {
                case "add":
                    s |= (1 << t);
                    break;
                case "remove":
                    s &= ~(1 << t);
                    break;
                case "check":
                    bw.write((s & (1 << t)) != 0 ? "1\n" : "0\n");
                    break;
                case "toggle":
                    s ^= (1 << t);
                    break;
                case "all":
                    s = (1 << 22) - 1;
                    break;
                default:
                    s = 0;
                    break;
            }
        }

        bw.flush();
    }
}
