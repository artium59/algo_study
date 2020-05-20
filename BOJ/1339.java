import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static char[] alphabet = new char[10];
    static String[] str;
    static int n, ans, size, visited;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(bf.readLine());

        str = new String[n];

        for (int i = 0; i < n; i++) {
            str[i] = bf.readLine();
            for (int j = 0; j < str[i].length(); j++) {
                if ((visited & 1<<(str[i].charAt(j)-'A')) != 0) continue;

                visited |= 1<<(str[i].charAt(j)-'A');
                alphabet[size++] = str[i].charAt(j);
            }
        }
        for ( ; size < 10; size++)
            alphabet[size] = 'a';

        perm(0);
        System.out.print(ans);
    }

    static int solve() {
        int[] arr = new int[n];
        int ret = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < str[i].length(); j++) {
                for (int k = 0; k < size; k++) {
                    if (str[i].charAt(j) != alphabet[k]) continue;

                    arr[i] = arr[i] * 10 + k;
                    break;
                }
            }
        }

        for (int a : arr)
            ret += a;

        return ret;
    }

    static void perm(int idx) {
        if (idx >= size) {
            ans = Math.max(ans, solve());
            return;
        }

        for (int i = idx; i < size; i++) {
            swap(idx, i);
            perm(idx+1);
            swap(idx, i);
        }
    }

    static void swap(int a, int b) {
        char ch = alphabet[a];
        alphabet[a] = alphabet[b];
        alphabet[b] = ch;
    }
}
