import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) dp[i][i] = 1;
        for (int i = 1; i < n; i++) if (nums[i] == nums[i + 1]) dp[i][i + 1] = 1;
        for (int i = 2; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                int index = j + i;
                if (nums[j] == nums[index] && dp[j + 1][index - 1] == 1) dp[j][index] = 1;
            }
        }
        int m = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            sb.append(dp[s][e]).append('\n');
        }
        System.out.println(sb);
    }
}
