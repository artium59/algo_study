import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> lst = new ArrayList<>();

        int n = sc.nextInt();
        long ans = 0;

        for (int i = 1; i <= 100000000; i*=10)
            lst.add(i-1);
        lst.add(100000000);

        for (int i = 1; i < lst.size(); i++) {
            if (n > lst.get(i))
                ans += (lst.get(i) - lst.get(i-1)) * i;
            else {
                ans += (n - lst.get(i-1)) * i;
                break;
            }
        }

        System.out.print(ans);
    }
}
