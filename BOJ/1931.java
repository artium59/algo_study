import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static ArrayList<Pair> lst = new ArrayList<>();
    static int n, a, b, ans=1, end;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(bf.readLine());
        n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());

            lst.add(new Pair(a, b));
        }
        Collections.sort(lst);

        end = lst.get(0).end;
        for (int i = 1; i < n; i++) {
            if (end <= lst.get(i).start) {
                ans++;
                end = lst.get(i).end;
            }
        }

        System.out.print(ans);
    }
}

class Pair implements Comparable<Pair> {
    int start, end;

    Pair(int a,  int b) {
        this.start = a;
        this.end = b;
    }

    @Override
    public int compareTo(Pair other) {
        if (end < other.end) return -1;
        else if (end > other.end) return 1;
        else {
            if (start > other.start) return 1;
            else return -1;
        }
    }
}
