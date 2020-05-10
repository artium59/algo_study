import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        int p = sc.nextInt();
        int m = sc.nextInt();
        int n = sc.nextInt();

        int cnt = 0;

        if (dogAttack(p, a, b)) cnt++;
        if (dogAttack(p, c, d)) cnt++;
        System.out.println(cnt);

        cnt = 0;
        if (dogAttack(m, a, b)) cnt++;
        if (dogAttack(m, c, d)) cnt++;
        System.out.println(cnt);

        cnt = 0;
        if (dogAttack(n, a, b)) cnt++;
        if (dogAttack(n, c, d)) cnt++;
        System.out.println(cnt);
    }

    static boolean dogAttack(int n, int a, int b) {
        return 0 < n % (a+b) && n % (a+b) <= a;
    }
}
