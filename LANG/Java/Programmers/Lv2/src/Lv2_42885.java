import java.util.Arrays;

public class Lv2_42885 {
    public static void main(String[] args) {
        Solution42885 s = new Solution42885();

    }
}

class Solution42885 {
    public static int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int index = 0;
        for (int i = people.length - 1; i >= 0; i--) {
            if (index > i) {
                break;
            }
            if (people[i] + people[index] <= limit) {
                index++;
            }
            answer++;
        }
        return answer;
    }
}