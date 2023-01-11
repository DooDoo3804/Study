import java.util.ArrayList;
import java.util.Arrays;

public class Lv1_68644 {
    public static void main(String[] args) {
        Solution68644 s = new Solution68644();
        //입력요소를 선언해줘야 출력값이 나옴
        int[] a = {2,1,3,4,1};
        s.solution(a);
    }
}

class Solution68644 {
    public int[] solution(int[] numbers) {
        ArrayList<Integer> numList = new ArrayList<Integer>();
        for (int i = 0; i<numbers.length; i ++) {
            for (int j = i + 1; j < numbers.length; j++) {
                int sumNum = numbers[i] + numbers[j];
                if (!numList.contains(sumNum)) {
                    numList.add(sumNum);
                }
            }
        }
        int[] answer = numList.stream().mapToInt(i->i).toArray();
        Arrays.sort(answer);
        System.out.println(Arrays.toString(answer));
        return answer;
    }
}