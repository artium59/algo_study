import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int r=1, c;
        char[][] arr;
        String str = sc.next();

        c = str.length();
        for (int i = 1; i <= c; i++) {
            if (str.length() % i == 0) {
                if (i > str.length() / i) break;
                r = i;
                c = str.length() / r;
            }
        }

        int k = 0;
        arr = new char[r][c];
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                arr[i][j] = str.charAt(k);
                k++;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                System.out.print(arr[i][j]);
        }
    }
}
