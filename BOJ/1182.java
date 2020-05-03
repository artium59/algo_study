import java.util.Scanner;

public class Main {
    static int[] arr = new int[20];
    static int n, s, ans=0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        s = sc.nextInt();
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        for (int i = 0; i < n; i++)
            ans += find(arr[i], i+1);

        System.out.print(ans);
    }

    static int find(int sum, int index) {
        if (index >= n) {
            if (sum == s) return 1;
            else return 0;
        }

        int ret = sum == s ? 1 : 0;

        for (int i = index; i < n; i++)
            ret += find(sum+arr[i], i+1);

        return ret;
    }
}
