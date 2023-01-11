import java.util.ArrayList;
public class Lv1_1845 {
    public static void main(String[] args) {
        Solution1845 s = new Solution1845();
        int[] nums = {3,1,2,3};
        s.solution(nums);
    }
}


class Solution1845 {
    public int solution(int[] nums) {
        int answer = 0;
        int maxSelect = nums.length / 2;
        ArrayList<Integer> selectedMonster = new ArrayList<Integer>();

        for (int i=0; i< nums.length; i++) {
            if (!selectedMonster.contains(nums[i]))
                selectedMonster.add(nums[i]);
        }
        if (selectedMonster.size() >= maxSelect)
            answer = maxSelect;
        else
            answer = selectedMonster.size();
        System.out.println(answer);
        return answer;
    }
}