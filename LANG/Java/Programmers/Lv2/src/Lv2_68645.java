import java.util.ArrayList;

public class Lv2_68645 {
    public static void main(String[] args) {
        Solution68645 s = new Solution68645();
        int n = 4;
        s.solution(n);
    }
}

class Solution68645 {
    public int[] solution(int n) {
        int[][] map = new int[n][n];
        int num = 1;
        int direction = 0;
        // 0:아래 1:오른쪽 2:좌상대각
        int finalNum = 0;
        for (int i=1; i<=n; i++) finalNum += i;
        int[] nowLoc = {0 ,0};
        // y, x

        while (num <= finalNum) {
            if (num == 1) {
                map[0][0] =1;
                num ++;
            }
            else if (direction == 0 ) {
                while (true) {
                    if (nowLoc[0]+1 < n && map[nowLoc[0]+1][nowLoc[1]] == 0) {
                        map[nowLoc[0]+1][nowLoc[1]] = num;
                        nowLoc[0] ++;
                        num ++;
                    }
                    else break;
                }
                direction ++;
            } else if (direction == 1) {
                while (true) {
                    if (nowLoc[1]+1 < n && map[nowLoc[0]][nowLoc[1]+1] == 0) {
                        map[nowLoc[0]][nowLoc[1]+1] = num;
                        nowLoc[1] ++;
                        num ++;
                    }
                    else break;
                }
                direction ++;
            } else if (direction == 2) {
                while (true) {
                    if (nowLoc[0] -1 >= 0 && nowLoc[1] -1 >= 0 && map[nowLoc[0]-1][nowLoc[1]-1] == 0) {
                        map[nowLoc[0]-1][nowLoc[1]-1] = num;
                        nowLoc[0] --;
                        nowLoc[1] --;
                        num ++;
                    }
                    else break;
                }
                direction = 0;
            }
        }

        ArrayList<Integer> answer = new ArrayList<>();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (map[i][j] != 0)
                    answer.add(map[i][j]);
            }
        }
        System.out.println(answer);
        return answer.stream().mapToInt(i->i).toArray();
    }
}