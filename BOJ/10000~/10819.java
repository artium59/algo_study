import java.util.*;

public class Main {
    static int[] arr = new int[8];
    static ArrayList<Integer> lst = new ArrayList<>();
    static boolean[] visited = new boolean[8];
    static int n, t=-1, ans=0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        find(1);
        System.out.print(ans);
    }

    static void find(int cnt) {
        if (cnt > n) {
            ans = Math.max(ans, calc());
            return;
        }

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            lst.add(arr[i]);
            find(cnt+1);
            lst.remove(lst.size()-1);
            visited[i] = false;
        }
    }

    static int calc() {
        int ret = 0 ;

        for (int i = 0; i < n-1; i++)
            ret += Math.abs(lst.get(i) - lst.get(i+1));

        return ret;
    }
}
