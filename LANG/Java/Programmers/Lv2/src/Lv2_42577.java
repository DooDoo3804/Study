import java.util.Arrays;

public class Lv2_42577 {
    public static void main(String[] args) {
        Solution42577 s = new Solution42577();
        String[] phone_book = {"119", "97674223", "1195524421"};
        s.solution(phone_book);
    }
}

class Solution42577 {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        for (String s : phone_book) {
        }
        for (int i = 0; i< phone_book.length-1; i++) {
            if (phone_book[i+1].startsWith(phone_book[i]))
                return false;
        }
        return answer;
    }
}