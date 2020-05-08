import java.util.Scanner;

public class Main {
    static int[] arr = new int[10000];
    static int n, t, smallIndex = -1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        for (int i = 0; i < n-1; i++) {
            if (arr[i] < arr[i+1]) smallIndex = i;
        }

        if (smallIndex == -1) {
            System.out.print("-1");
            return;
        }

        for (int i = n-1; i > smallIndex; i--) {
            if (arr[smallIndex] < arr[i]) {
                t = arr[smallIndex];
                arr[smallIndex] = arr[i];
                arr[i] = t;
                break;
            }
        }

        for (int i = 0; i <= smallIndex; i++)
            System.out.print(arr[i]+" ");
        for (int i = n-1; i > smallIndex; i--)
            System.out.print(arr[i]+" ");
    }
}
