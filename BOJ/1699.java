import java.util.*;

public class Main {
    static int[] arr;
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[n+1];

        for (int j = 1; j*j <= n; j++)
            arr[j*j] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; i+j*j <= n; j++) {
                if (arr[i + j*j] == 0) arr[i + j*j] = arr[i]+1;
                else arr[i+ j*j] = Math.min(arr[i + j*j], arr[i]+1);
            }
        }
        System.out.print(arr[n]);
    }
}
