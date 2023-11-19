import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] dp = new int[n];
        int[] nums = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) nums[i] = Integer.parseInt(st.nextToken());

        dp[0] = nums[0];
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (dp[index] < nums[i]) dp[++index] = nums[i];
            else {
                int temp = Arrays.binarySearch(dp, 0, index, nums[i]);
                if (temp < 0) temp = -(temp + 1);
                dp[temp] = nums[i];
            }
        }

        System.out.println(index + 1);
    }
}
