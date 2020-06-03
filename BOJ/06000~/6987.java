import java.io.*;
import java.util.*;

public class Main {
    static boolean bb;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] arr;

		for (int z = 0; z < 4; z++) {
		    StringTokenizer st = new StringTokenizer(br.readLine());
		    arr = new int[6][3];
		    bb = false;

		    for (int i = 0; i < 6; i++) {
		        for (int j = 0; j < 3; j++)
		            arr[i][j] = Integer.parseInt(st.nextToken());
		    }

            find(arr, 0, 1);
		    System.out.print(bb ? "1 " : "0 ");
		}
	}

	private static void find(int[][] arr, int a, int b) {
	    if (a == 5) {
	        bb = check(arr);
            return;
	    }

        if (arr[a][0] > 0 && arr[b][2] > 0) {
            arr[a][0]--;
            arr[b][2]--;

            if (b == 5) find(arr, a+1, a+2);
            else find(arr, a, b+1);

            arr[a][0]++;
            arr[b][2]++;
        }

        if (bb) return;

        if (arr[a][1] > 0 && arr[b][1] > 0) {
            arr[a][1]--;
            arr[b][1]--;

            if (b == 5) find(arr, a+1, a+2);
            else find(arr, a, b+1);

            arr[a][1]++;
            arr[b][1]++;
        }

        if (bb) return;

        if (arr[a][2] > 0 && arr[b][0] > 0) {
            arr[a][2]--;
            arr[b][0]--;

            if (b == 5) find(arr, a+1, a+2);
            else find(arr, a, b+1);

            arr[a][2]++;
            arr[b][0]++;
        }

        if (bb) return;
	}

	private static boolean check(int[][] arr) {
	    for (int i = 0; i < 6; i++) {
	        for (int j = 0; j < 3; j++) {
	            if (arr[i][j] != 0)
	                return false;
	        }
	    }
	    return true;
	}
}
