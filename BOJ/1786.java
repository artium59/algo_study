import java.io.*;
import java.util.*;

public class Main {
    static String t, p;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        t = br.readLine();
        p = br.readLine();

        List<Integer> list = KMP();

        System.out.printf("%d\n", list.size());
        list.forEach((l)-> System.out.print(l+" "));
    }

    private static List<Integer> KMP() {
        List<Integer> list = new ArrayList<>();
        int[] jump = getJump();
        int j = 0, size = p.length();

        for (int i = 0; i < t.length(); i++) {
            while (j > 0 && t.charAt(i) != p.charAt(j))
                j = jump[j-1];

            if (t.charAt(i) == p.charAt(j)) {
                if (j == size-1) {
                    list.add(i-size+2);
                    j = jump[j];
                }
                else
                    ++j;
            }
        }

        return list;
    }

    private static int [] getJump() {
        int j = 0, size = p.length();
        int[] ret = new int[size];

        for (int i = 1; i < size; i++) {
            while (j > 0 && p.charAt(i) != p.charAt(j))
                j = ret[j-1];

            if (p.charAt(i) == p.charAt(j))
                ret[i] = ++j;
        }

        return ret;
    }
}
