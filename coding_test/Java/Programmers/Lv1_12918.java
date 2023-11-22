
public class Lv1_12918 {
    public boolean solution(String s) {
        boolean answer = true;
        if (s.length() == 4 || s.length() == 6) {
            for (int i=0; i<s.length(); i++) {
                if (Character.isDigit(s.charAt(i))) {
                    
                }
                else {
                    answer = false;
                    break;
                }
            }
        }
        else {
            answer = false;
        }
        return answer;
    }
}
