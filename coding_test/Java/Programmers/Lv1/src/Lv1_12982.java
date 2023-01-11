import java.util.Arrays;

public class Lv1_12982 {
    public int solution(int[] d, int budget) {
        int answer = 0;
        Arrays.sort(d);
        for (int b : d) {
            budget -= b;
            answer ++;
            if (budget == 0) {
                break;
            }
            else if (budget < 0) {
                answer --;
                break;
            }
        }
        return answer;
    }
}
