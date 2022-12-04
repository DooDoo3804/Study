import java.util.*;
public class Lv1_12906 {
    public int[] solution(int []arr) {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        answer.add(arr[0]);
        for (int i : arr) {
            if (answer.get(answer.size()-1) != i) {
                answer.add(i);
            }
        }
        int[] trueAnswer = answer.stream().mapToInt(i -> i).toArray();
        return trueAnswer;
    }
}
