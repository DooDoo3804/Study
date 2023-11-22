
public class Lv2_87390 {
    public static void main(String[] args) {
        Solution87390 s = new Solution87390();
        int n = 3;
        long left = 2;
        long right = 5;
        s.solution(n, left, right);
    }
}


class Solution87390 {
    public int[] solution(int n, long left, long right) {
        int answerSize = (int) (right - left) + 1;
        int[] answer = new int[answerSize];

        int index = 0;
        for (long i = left; i < right+1; i++) {
            long rows = i / n;
            long cols = i % n;
            if (rows <= cols) answer[index] = (int) cols+1;
            else answer[index] = (int) rows+1;
            index ++;
        }
        return answer;
    }
}