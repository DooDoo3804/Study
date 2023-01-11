import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lv2_17684 {
    public static void main(String[] args) {
        Solution17684 s = new Solution17684();
        String msg = "KAKAO";
        s.solution(msg);
    }
}

class Solution17684 {
    public int[] solution(String msg) {
        ArrayList<Integer> answer = new ArrayList<>();
        Map<String, Integer> keyList =  new HashMap<>();
        char ch = 65;
        for (int i = 1; i <=26; i++) {
            keyList.put(String.valueOf(ch), i);
            ch ++;
        }
        int index = 0;
        String subString1 = "";
        String subString2 = "";
        while (index < msg.length()) {
            subString2 = subString1.toString();
            subString1 += Character.toString(msg.charAt(index));
            if (keyList.containsKey(subString1)) {
                if (index == msg.length()-1)
                    answer.add(keyList.get(subString1));
                index ++;
            } else {
                answer.add(keyList.get(subString2));
                if (index == msg.length()-1) {
                    answer.add(keyList.get(Character.toString(msg.charAt(index))));
                    index ++;
                }
                keyList.put(subString1, keyList.size()+1);
                subString1 = "";
            }
        }
        System.out.println(answer);
        return answer.stream().mapToInt(i->i).toArray();
    }
}