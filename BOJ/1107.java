import java.util.*;

public class Main {
    static int n, m;
    static boolean[] broken = new boolean[10];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 0; i < m; i++)
            broken[sc.nextInt()] = true;

        System.out.print(find());
    }

    static int find() {
        int up = Integer.MAX_VALUE, down = Integer.MAX_VALUE;
        for (int i = n; i < 1000000; i++) {
            if (possible(i)) {
                up = (i-n) + count(i);
                break;
            }
        }

        for (int i = n; i >= 0; i--) {
            if (possible(i)) {
                down = (n-i) + count(i);
                break;
            }
        }

        return Math.min(Math.min(up, down), Math.abs(n-100));
    }

    static boolean possible(int num) {
        if (num == 0) return !broken[0];

        while (num > 0) {
            if (broken[num%10])
                return false;
            num /= 10;
        }

        return true;
    }

    static int count(int num) {
        if (num == 0) return 1;

        int ret = 0;
        for ( ; num > 0; ret++)
            num /= 10;

        return ret;
    }
}
