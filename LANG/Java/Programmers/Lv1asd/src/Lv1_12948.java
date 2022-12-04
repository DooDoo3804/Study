
public class Lv1_12948 {
    public String solution(String phone_number) {
        String answer = "";
        int totalLength = phone_number.length();
        for (int i=0; i<phone_number.length()-4; i++) {
            answer += "*";      
        }
        answer += phone_number.substring(phone_number.length()-4,phone_number.length());
//      python에서 slicing의 개념 substring
        return answer;
    }
}
