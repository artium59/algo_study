import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static Room head = new Room();

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        for (int a = 0; a < n; a++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            Room room = head;

            int k = Integer.parseInt(st.nextToken());
            for (int b = 0; b < k; b++) {
                String str = st.nextToken();
                if (!room.map.containsKey(str))
                    room.map.put(str, new Room());

                room = room.map.get(str);
            }
        }

        System.out.print(output(head, 0).toString());
    }

    private static StringBuilder output(Room r, int floor) {
        StringBuilder sb = new StringBuilder();
        r.map.forEach((a, b) -> {
            for (int i = 0; i < floor; i++)
                sb.append("--");
            sb.append(a).append("\n");
            sb.append(output(b, floor+1));
        });

        return sb;
    }
}

class Room {
    Map<String, Room> map;

    Room() {
        map = new TreeMap<>();
    }
}
