import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        class App implements Comparable{
            int memory;
            int cost;
            App () { }
            @Override
            public int compareTo(Object o) {
                App a = (App) o;
                return this.cost - a.cost;
            }

        }
        ArrayList<App> apps = new ArrayList<>();
        for (int i =0; i < n; i++) apps.add(new App());
        st = new StringTokenizer(br.readLine());
        for (int i =0; i < n; i++) {
            int memory = Integer.parseInt(st.nextToken());
            apps.get(i).memory = memory;
        }
        st = new StringTokenizer(br.readLine());
        int max_cost = 0;
        for (int i =0; i < n; i++) {
            int cost = Integer.parseInt(st.nextToken());
            apps.get(i).cost = cost;
            max_cost += cost;
        }
        Collections.sort(apps);
        int[] dp = new int[max_cost + 1];
        int totalCost = 0;
        for (App app : apps) {
            totalCost += app.cost;
            for (int i = totalCost; i >= app.cost; i--) {
                dp[i] = Math.max(dp[i], dp[i - app.cost] + app.memory);
            }
        }
        for (int i = 0; i <= max_cost; i++) if (dp[i] >= m) {
            System.out.println(i);
            break;
        }

    }
}
