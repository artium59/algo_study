import java.io.*;

public class Main {
    static final long[] prime = {1234567891L, 1000000321L};
    static final long mul = 31L, key_mul = 1000000009L;
    static long ret1 = 0, ret2 = 0, del1 = 1, del2 = 1, key;
    static String s, p;
    static boolean check = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        s = br.readLine();
        p = br.readLine();

        int size = p.length();
        for (int i = 0; i < size; i++) {
            ret1 = (ret1 * mul + p.charAt(i)-'a') % prime[0];
            ret2 = (ret2 * mul + p.charAt(i)-'a') % prime[1];

            if (i < size-1) {
                del1 = (del1 * mul) % prime[0];
                del2 = (del2 * mul) % prime[1];
            }
        }
        key = ret1 * key_mul + ret2;

        ret1 = ret2 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i >= size) {
                ret1 = (ret1 - ((s.charAt(i-size)-'a')*del1)%prime[0] + prime[0]) % prime[0];
                ret2 = (ret2 - ((s.charAt(i-size)-'a')*del2)%prime[1] + prime[1]) % prime[1];
            }

            ret1 = (ret1 * mul + s.charAt(i)-'a') % prime[0];
            ret2 = (ret2 * mul + s.charAt(i)-'a') % prime[1];

            if (i < size-1) continue;

            check = key == ret1 * key_mul + ret2;
            if (check) break;
        }

        System.out.print(check ? "1" : "0");
    }
}
