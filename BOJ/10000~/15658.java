import java.util.Scanner;

public class Main {
    static int[] arr = new int[11];
    static int[] operator = new int[4];
    static int n, t=-1, max=-1234567890, min=1234567890;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        for (int i = 0; i < 4; i++) operator[i] = sc.nextInt();

        find(arr[0], 1);
        System.out.printf("%d\n%d", max, min);
    }

    static void find(int result, int index) {
        if (index >= n) {
            max = Math.max(max, result);
            min = Math.min(min, result);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (operator[i] <= 0) continue;
            operator[i]--;

            if (i == 0) find(result+arr[index], index+1);
            else if (i == 1) find(result-arr[index], index+1);
            else if (i == 2) find(result*arr[index], index+1);
            else find(result/arr[index], index+1);

            operator[i]++;
        }
    }
}
