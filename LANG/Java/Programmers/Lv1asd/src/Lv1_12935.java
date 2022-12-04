import java.util.ArrayList;

public class Lv1_12935 {
	public int[] solution(int[] arr) {
        ArrayList<Integer> answer = new ArrayList<>();
        int minNum = arr[0];
        
        for (int i : arr) {
            if (minNum>i) {
                minNum = i;
            }
        }
        for (int j=0; j<arr.length; j++) {
        if (arr[j] != minNum) {
            answer.add(arr[j]);
            }
        }
        
        if (answer.size() == 0) {
            answer.add(-1);
        }        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}
