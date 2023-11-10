import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] indegree = new int[32001];
        ArrayList<ArrayList<Integer>> students = new ArrayList<>();
        for (int i = 0; i <= n; i++) students.add(new ArrayList<>());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            students.get(a).add(b);
            indegree[b]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) q.add(i);
        }
        while (!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append(" ");
            for (int next : students.get(now)) {
                if (--indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
        System.out.println(sb);
    }
}
