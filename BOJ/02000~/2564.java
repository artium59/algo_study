import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Pair> shops = new ArrayList<>();
        int c = sc.nextInt(), r = sc.nextInt(), t = sc.nextInt(), ans = 0, a, b;

        for (int i = 0; i < t; i++) {
            a = sc.nextInt();
            b = sc.nextInt();

            shops.add(new Pair(a, b));
        }
        a = sc.nextInt();
        b = sc.nextInt();

        for (Pair s : shops) {
            if (s.axis == 1) {
                if (a == 1)
                    ans += Math.abs(b - s.loc);
                else if (a == 2)
                    ans += r + Math.min(Math.abs(b + s.loc), Math.abs(2*c - b - s.loc));
                else if (a == 3)
                    ans += s.loc + b;
                else
                    ans += c - s.loc + b;
            }
            else if (s.axis == 2) {
                if (a == 1)
                    ans += r + Math.min(Math.abs(b + s.loc), Math.abs(2*c - b - s.loc));
                else if (a == 2)
                    ans += Math.abs(b - s.loc);
                else if (a == 3)
                    ans += r - b + s.loc;
                else
                    ans += r - b + c - s.loc;
            }
            else if (s.axis == 3) {
                if (a == 1)
                    ans += b + s.loc;
                else if (a == 2)
                    ans += r - s.loc + b;
                else if (a == 3)
                    ans += Math.abs(b - s.loc);
                else
                    ans += c + Math.min(Math.abs(b + s.loc), Math.abs(2*r - b - s.loc));
            }
            else {
                if (a == 1)
                    ans += c - b + s.loc;
                else if (a == 2)
                    ans += c - b + r - s.loc;
                else if (a == 3)
                    ans += c + Math.min(Math.abs(b + s.loc), Math.abs(2*r - b - s.loc));
                else
                    ans += Math.abs(b - s.loc);
            }
        }

        System.out.print(ans);
    }
}

class Pair {
    int axis, loc;
    Pair(int a, int b) {
        this.axis = a;
        this.loc = b;
    }
}
