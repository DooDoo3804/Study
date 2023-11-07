import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int answer = 0;
        int[] arr = new int[n + 1];
        int[] dp = new int[100001];

        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] + Integer.parseInt(br.readLine());
        }
        dp[m] = arr[m];
        for (int i = m + 1; i <= n; i++) {
            dp[i] = Math.max(dp[i - 1] + arr[i] - arr[i - 1], arr[i] - arr[i - m]);
        }
        for (int i = 1; i <= n; i++) answer = Math.max(answer, dp[i]);
        System.out.println(answer);
    }
}
