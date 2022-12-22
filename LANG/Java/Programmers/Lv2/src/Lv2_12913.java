import java.util.Arrays;

public class Lv2_12913 {
    public static void main(String[] args) {
        Solution12913 s = new Solution12913();
        int[][] land = {{1,2,3,5}, {5,6,7,8}, {4,3,2,1}};
        s.solution(land);
    }
}

class Solution12913 {
    int solution(int[][] land) {
        for (int i = 1; i<land.length; i++) {
            land[i][0] += Math.max(Math.max(land[i-1][1], land[i-1][2]), land[i-1][3]);
            land[i][1] += Math.max(Math.max(land[i-1][0], land[i-1][2]), land[i-1][3]);
            land[i][2] += Math.max(Math.max(land[i-1][1], land[i-1][0]), land[i-1][3]);
            land[i][3] += Math.max(Math.max(land[i-1][1], land[i-1][0]), land[i-1][2]);
        }
        int[] answer = land[land.length-1];
        Arrays.sort(answer);
        return answer[answer.length-1];
    }
}
// DP 풀이법
