import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        PriorityQueue<Integer> small = new PriorityQueue<>((o1, o2) -> -Integer.compare(o1, o2));
        PriorityQueue<Integer> big = new PriorityQueue<>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            int k = Integer.parseInt(br.readLine());

            if (i == 0)
                small.add(k);
            else {
                if (small.peek() < k) {
                    big.add(k);
                    if (small.size() < big.size())
                        small.add(big.poll());
                }
                else {
                    small.add(k);
                    if (small.size() > big.size() + 1)
                        big.add(small.poll());
                }
            }

            sb.append(small.peek()).append('\n');
        }

        System.out.println(sb.toString());
    }
}
