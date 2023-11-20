import java.io.*;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n;
    static int[][] board;
    // 상, 우, 하, 좌
    static int[][] moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static int[][] check;
    static int answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        check = new int[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < 4; i++) {
            sumBoard(i, 0);
        }
        System.out.println(answer);
    }
    public static void sumBoard(int m, int c) {

        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++)
            Arrays.fill(check[i], 0);

        for (int i = 0 ; i < n; i++)
            temp[i] = board[i].clone();

        if (c == 5) return;


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int nowI = (m == 0 || m == 3) ? i : n - 1 - i;
                int nowJ = (m == 0 || m == 3) ? j : n - 1 - j;
                int nextI = nowI;
                int nextJ = nowJ;

                if (board[nowI][nowJ] == 0) continue;
                if (check[nowI][nowJ] == 1) continue;

                while (true) {
                    nextI += moves[(m + 2) % 4][0];
                    nextJ += moves[(m + 2) % 4][1];

                    if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >=n) break;
                    if (board[nextI][nextJ] == 0) continue;
                    if (board[nowI][nowJ] != board[nextI][nextJ]) break;

                    if (board[nowI][nowJ] == board[nextI][nextJ]) {
                        board[nextI][nextJ] *= 2;
                        check[nextI][nextJ] = 1;
                        board[nowI][nowJ] = 0;
                        break;
                    }
                }
            }
        }

        moveBoard(m);

        for (int mm = 0; mm < 4; mm++) {
            sumBoard(mm, c + 1);
        }

        for (int i = 0 ; i < n; i++)
            board[i] = temp[i].clone();
    }
    static void moveBoard(int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int nowI = (m == 0 || m == 3) ? i : n - 1 - i;
                int nowJ = (m == 0 || m == 3) ? j : n - 1 - j;
                int nextI = nowI;
                int nextJ = nowJ;
                if (board[nowI][nowJ] == 0) continue;
                answer = Math.max(answer, board[nowI][nowJ]);

                int subNum = board[nowI][nowJ];
                while (true) {
                    nextI += moves[m][0];
                    nextJ += moves[m][1];
                    if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >=n) break;
                    if (board[nextI][nextJ] != 0) break;
                    board[nextI - moves[m][0]][nextJ - moves[m][1]] = 0;
                    board[nextI][nextJ] = subNum;
                }
            }
        }
    }

}
