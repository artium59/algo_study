import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), sum, ans=0;
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                sum = arr[i] + arr[j];

                for (int k = j+1; k < n; k++) {
                    if (ans < sum+arr[k] && sum+arr[k] <= m)
                        ans = sum + arr[k];
                }
            }
        }

        System.out.print(ans);
    }
}
