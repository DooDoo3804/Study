import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] indegree = new int[n + 1];
        ArrayList<ArrayList<Integer>> singers = new ArrayList<>();
        for (int i = 0; i <= n; i++) singers.add(new ArrayList<>());

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int before_num = 0;
            int now_num = 0;
            int singer_num = Integer.parseInt(st.nextToken());
            for (int j = 0; j < singer_num; j++) {
                before_num = now_num;
                now_num = Integer.parseInt(st.nextToken());
                if (before_num != 0) {
                    singers.get(before_num).add(now_num);
                    indegree[now_num]++;
                }
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++)
            if (indegree[i] == 0) q.add(i);
        int cnt = 0;
        while(!q.isEmpty()) {
            int now = q.poll();
            sb.append(now).append('\n');
            cnt++;
            for (int s : singers.get(now)) {
                if (--indegree[s] == 0) {
                    q.add(s);
                }
            }
        }
        if (cnt == n) System.out.println(sb);
        else System.out.println(0);
    }
}
