import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(arr);

        int x = Integer.parseInt(br.readLine());

        int l = 0, r = n-1, ans = 0;
        while (l < r) {
            int sum = arr[l] + arr[r];
            if (sum == x) {
                ++ans;
                ++l; --r;
            }
            else if (sum < x)
                ++l;
            else
                --r;
        }

        System.out.println(ans);
    }
}
