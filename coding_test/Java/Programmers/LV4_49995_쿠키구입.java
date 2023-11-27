import java.util.*;

class Solution {
    public int solution(int[] cookie) {
        int answer = 0;
        int n = cookie.length;
        for (int i = 0; i < n - 1; i++) {
            int lSum = cookie[i];
            int rSum = cookie[i + 1];
            int l = i;
            int r = i + 1;
            while(true) {
                if (lSum == rSum) {
                    answer = Math.max(answer, lSum);
                }if (l > 0 && lSum <= rSum) {
                    lSum += cookie[--l];
                } else if (r < n - 1 && lSum >= rSum) {
                    rSum += cookie[++r];
                } else {
                    break;
                }
            }
        }
        
        
        
        return answer;
    }
}