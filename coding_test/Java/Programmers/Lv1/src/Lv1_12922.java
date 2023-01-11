
public class Lv1_12922 {
    public String solution(int n) {
        String answer = "";
        int a = (int)n / 2;
        int b = (int)n % 2;
        for (int i = 0; i<a; i++) {
            answer += "수박";
        }
        if (b == 1) {
            answer += "수";
        }
        return answer;
    }
}
