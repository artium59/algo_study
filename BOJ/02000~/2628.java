import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> yrr = new ArrayList<>();
        ArrayList<Integer> xrr = new ArrayList<>();
        int r = sc.nextInt(), c = sc.nextInt(), t = sc.nextInt(), a, b, ans=0;

        yrr.add(0); yrr.add(c);
        xrr.add(0); xrr.add(r);

        while (t-- > 0) {
            a = sc.nextInt();
            b = sc.nextInt();

            if (a == 0) yrr.add(b);
            else xrr.add(b);
        }
        Collections.sort(yrr); Collections.sort(xrr);

        for (int yIdx = 1; yIdx < yrr.size(); yIdx++) {
            for (int xIdx = 1; xIdx < xrr.size(); xIdx++)
                ans = Math.max(ans, (yrr.get(yIdx)-yrr.get(yIdx-1))*(xrr.get(xIdx)-xrr.get(xIdx-1)));
        }

        System.out.println(ans);
    }
}
