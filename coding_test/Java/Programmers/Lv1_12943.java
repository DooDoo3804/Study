
public class Lv1_12943 {
    public int solution(long num) {
        int answer = 0;
        while (num != 1) {
            if (answer == 500) {
                answer = -1;
                break;
            }
            num = num % 2 == 0 ? num / 2 : num * 3 + 1;
            // 삼항 연산자 사용 주의
            answer += 1;
        }
        return answer;
    }
}
