import java.util.ArrayList;
import java.util.Arrays;

public class Lv1_72410 {
    public static void main(String[] args) {
        Solution72410 s = new Solution72410();
        String new_id = "abcdefghijklmn.p";
        s.solution(new_id);

    }
}

class Solution72410 {
    public String solution(String new_id) {
        // step 1
        new_id = new_id.toLowerCase();
        // step 2
        char[] allowId = {'-', '_', '.'};
        ArrayList<Character> userIdChar2 = new ArrayList<>();
        for (int i = 0; i < new_id.length(); i++) {
            if (Character.isAlphabetic(new_id.charAt(i)) || Character.isDigit(new_id.charAt(i))) {
                userIdChar2.add(new_id.charAt(i));
            }
            for (int j = 0; j < allowId.length; j ++) {
                if (allowId[j] == new_id.charAt(i)) {
                    userIdChar2.add(new_id.charAt(i));
                    break;
                }
            }
        }
        // step 3
        boolean commaCheck = false;
        ArrayList<Character> userIdChar3 = new ArrayList<>();
        for (int i = 0; i < userIdChar2.size(); i++) {
            if (userIdChar2.get(i) == '.' && commaCheck == false) {
                commaCheck = true;
                userIdChar3.add(userIdChar2.get(i));
            } else if (userIdChar2.get(i) != '.') {
                commaCheck = false;
                userIdChar3.add(userIdChar2.get(i));
            }
        }
        //step 4
        if (!userIdChar3.isEmpty() && userIdChar3.get(0) == '.')
            userIdChar3.remove(0);
        if (!userIdChar3.isEmpty() && userIdChar3.get(userIdChar3.size()-1) == '.')
            userIdChar3.remove(userIdChar3.size()-1);
        // step 5
        if (userIdChar3.isEmpty())
            userIdChar3.add('a');
        // step 6
        ArrayList<Character> userIdChar4 = new ArrayList<>();
        if (userIdChar3.size() > 15) {
            for (int i = 0; i<15 ; i ++){
                userIdChar4.add(userIdChar3.get(i));
            }
            if (userIdChar4.get(userIdChar4.size()-1) == '.')
                userIdChar4.remove(userIdChar4.size()-1);
        }
        // step 7
        else if (userIdChar3.size() <= 2) {
            for (int i = 0; i<userIdChar3.size(); i++) {
                userIdChar4.add(userIdChar3.get(i));
            }
            while (userIdChar4.size() != 3) {
                userIdChar4.add(userIdChar3.get(userIdChar3.size()-1));
            }
        }
        else {
            for (int i = 0; i<userIdChar3.size(); i++) {
                userIdChar4.add(userIdChar3.get(i));
            }
        }
        String answer = new String();
        for (int i = 0; i<userIdChar4.size() ; i ++){
            answer += userIdChar4.get(i).toString();
        }
        System.out.println(answer);
        return answer;
    }
}

