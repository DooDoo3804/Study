import java.util.Arrays;

public class Lv1_77484 {
    public static void main(String[] args) {
        Solution77484 s = new Solution77484();
        int[] lottos = {44,1,0,0,31,25};
        int[] win_nums = {31,10,45,1,6,19};
        s.solution(lottos, win_nums);
    }
}

class Solution77484 {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        int[] prize = {6, 6, 5, 4, 3, 2, 1};
        int possibleNums = 0;
        int possibleChange = 0;

        for (int i : lottos) {
            for (int j : win_nums) {
                if ( i == j)
                    possibleNums ++;
            }
            if (i==0)
                possibleChange ++;
        }
        answer[1] = prize[possibleNums];
        if (possibleNums + possibleChange> 6) {
            answer[0] = prize[6];
        }
        else
            answer[0] = prize[possibleNums + possibleChange];

        System.out.println(Arrays.toString(answer));
        return answer;
    }
}