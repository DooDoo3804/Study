import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();
        int[][] dp = new int[1001][1001];
        int[][] lcs = new int[1001][1001];

        for (int i = 0 ; i < A.length(); i++) {
            for (int j = 0; j < B.length(); j++) {
                if (A.substring(i, i + 1).equals(B.substring(j, j + 1))) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    lcs[i + 1][j + 1] = 1;
                } else {
                    if (dp[i + 1][j] > dp[i][j + 1]) {
                        dp[i + 1][j + 1] = dp[i + 1][j];
                        lcs[i + 1][j + 1] = 3;
                    }
                    else {
                        dp[i + 1][j + 1] = dp[i][j + 1];
                        lcs[i + 1][j + 1] = 2;
                    }
                }

            }
        }
        int idx_i = A.length();
        int idx_j = B.length();
        String answer = "";

        while(idx_i >= 0 && idx_j >= 0) {
            if (lcs[idx_i][idx_j] == 1) {
                answer = A.substring(idx_i - 1, idx_i) + answer;
                idx_i--;
                idx_j--;
            } else if (lcs[idx_i][idx_j] == 2) {
                idx_i--;
            } else idx_j--;
        }

        System.out.println(dp[A.length()][B.length()]);
        System.out.println(answer);
    }
}
