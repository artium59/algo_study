import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> {
            int ao1 = Math.abs(o1), ao2 = Math.abs(o2);

            if (ao1 == ao2) return Integer.compare(o1, o2);
            else return Integer.compare(ao1, ao2);
        });
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int x = Integer.parseInt(br.readLine());

            if (x != 0)
                pq.add(x);
            else
                sb.append(pq.peek() == null ? 0 : pq.poll()).append('\n');
        }

        System.out.println(sb.toString());
    }
}
