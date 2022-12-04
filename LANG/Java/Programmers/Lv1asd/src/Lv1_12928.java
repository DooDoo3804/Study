import java.util.ArrayList;

public class Lv1_12928 {
    public int solution(int n) {
        int answer = 0;
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        int i = 0;
        while (i < n) {
            i += 1;
            if ((int)n%i == 0){
                arrayList.add(i);
            }
        }
        for (int j:arrayList) {
        	answer += j;
        }
        return answer;
    }
}
