import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static boolean answer_check = false;
    static int last_x = 0;
    static int last_y = 0;


    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int[][] arr = new int[9][9];
        for (int i = 0; i < 9; i++) {
            String input = bf.readLine();
            for (int j = 0; j < 9; j++) {
                arr[i][j] = Integer.parseInt(input.substring(j, j + 1));
                if (arr[i][j] == 0) {
                    last_x = i;
                    last_y = j;
                }
            }
        }

        TotalArr total_arr = new TotalArr(arr);
        total_arr.fill_number();
        total_arr.printArr();
    }

    static class TotalArr {

        private int[][] total_map;

        TotalArr(int[][] arr) {
            total_map = new int[9][9];
            for(int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    total_map[i][j] = arr[i][j];
                }
            }
        }

        void printArr() {
            for (int i = 0 ; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(total_map[i][j]);
                }
                System.out.println();
            }
        }
        void fill_number() {
            if (answer_check) return;
            boolean fill_check;

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (total_map[i][j] != 0) continue;
                    else {
                        fill_check = false;
                        for (int k = 1; k <= 9; k++) {
                            if (check_ver(i, j, k) && check_hrz(i, j, k) && check_box(i, j, k)) {
                                fill_check = true;
                                total_map[i][j] = k;
                                if (i == last_x && j == last_y) answer_check = true;
                                fill_number();
                                if (answer_check) return;
                                total_map[i][j] = 0;
                            }
                            fill_check = false;
                        }
                    }
                    if (!fill_check) return;
                }
            }
        }
        boolean check_hrz(int x, int y, int k) {
            boolean check = true;
            for (int i = 0 ; i < 9; i++) {
                if (total_map[x][i] == k) {
                    check = false;
                    break;
                }
            }
            return check;
        }

        boolean check_ver(int x, int y, int k) {
            boolean check = true;
            for (int i = 0 ; i < 9; i++) {
                if (total_map[i][y] == k) {
                    check = false;
                    break;
                }
            }
            return check;
        }

        boolean check_box(int x, int y, int k) {
            boolean check = true;
            int box_x = 3 * (x / 3);
            int box_y = 3 * (y / 3);

            for (int i = 0 ; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (total_map[box_x + i][box_y + j] == k) {
                        check = false;
                        break;
                    }
                }
                if (!check) break;
            }
            return check;
        }
    }


}