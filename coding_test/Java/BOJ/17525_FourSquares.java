import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());

        int[] dp = new int[50001];
        for (int i = 0; i <= 50000; i++) dp[i] = Integer.MAX_VALUE;
        dp[0] = 0;

        for (int i = 1; i <= (int) (Math.sqrt(50000) + 1); i++) {
            int interval = i * i;
            for (int j = 0; j <= interval * 4; j++) {
                if (j + interval > 50000 || j > 50000) continue;
                if (dp[j] >= 4) continue;
                dp[j + interval] = Math.min(dp[j] + 1, dp[j + interval]);
            }
        }
        System.out.println(dp[n]);
    }
}