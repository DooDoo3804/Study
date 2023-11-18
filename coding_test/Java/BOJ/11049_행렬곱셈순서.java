import java.io.*;
import java.util.*;

public class Main {
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        class Matrix {
            int r; int c;
            Matrix(int r, int c) {
                this.r = r;
                this.c = c;
            }
        }
        Matrix[] matrix = new Matrix[n + 1];
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = 2134567890;

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            matrix[i] = new Matrix(r, c);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j >= 1; j--) {
                if (i - j == 1) {
                    dp[j][i] = Math.min(dp[j][i], matrix[j].r * matrix[j].c * matrix[i].c);
                } else if (i == j) dp[j][i] = 0;
                else {
                    for (int k = j + 1; k <= i - 1; k++) {
                        int temp1 = dp[j][k] + dp[k + 1][i] + matrix[j].r * matrix[k].c * matrix[i].c;
                        int temp2 = dp[j][k - 1] + dp[k][i] + matrix[j].r * matrix[k].r * matrix[i].c;
                        dp[j][i] = Math.min(dp[j][i], Math.min(temp1, temp2));
                    }
                }

            }
        }

        System.out.println(dp[1][n]);

    }
}
