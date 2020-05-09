import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        boolean[] cake = new boolean[l];
        int n = sc.nextInt();
        int ans=0, expect=0, ans_cnt=0, expect_cnt=0, tmp;

        for (int i = 0; i < n; i++) {
            int a = sc.nextInt(); a--;
            int b = sc.nextInt();
            tmp = 0;

            if (expect_cnt < b-a) {
                expect_cnt = b-a;
                expect = i+1;
            }

            for ( ; a < b; a++) {
                if (!cake[a]) tmp++;
                cake[a] = true;
            }

            if (tmp > ans_cnt) {
                ans_cnt = tmp;
                ans = i+1;
            }
        }

        System.out.printf("%d\n%d", expect, ans);
    }
}
