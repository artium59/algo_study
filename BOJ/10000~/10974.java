import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static ArrayList<Integer> lst = new ArrayList<>();
    static boolean[] visited = new boolean[9];
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        find(1);

    }

    static void find(int count) {
        if (count > n) {
            for (int i = 0; i < n; i++) {
                System.out.print(lst.get(i));
                if (i != n-1) System.out.print(" ");
            }
            System.out.println();
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            visited[i] = true;
            lst.add(i);
            find(count+1);
            lst.remove(lst.size()-1);
            visited[i] = false;
        }
    }
}
