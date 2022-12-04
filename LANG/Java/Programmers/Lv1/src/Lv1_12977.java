import java.util.ArrayList;

public class Lv1_12977 {
    public static void main(String[] args) {
        Solution12977 s = new Solution12977();
        int[] nums = {1,2,3,4};
        s.solution(nums);
    }
}

class Solution12977 {
    public int solution(int[] nums) {
        int answer = 0;
        for (int i =0; i<nums.length; i++) {
            for (int j=i+1; j<nums.length; j++) {
                for (int k=j+1; k<nums.length; k++) {
                    int subSum = nums[i] +nums[j] + nums[k];
                    ArrayList<Integer> subArrayList = new ArrayList<Integer>();
                    for (int l=1; l<=subSum; l++) {
                        if (subSum % l == 0) {
                            subArrayList.add(l);
                        }
                    }
                    if (subArrayList.size() == 2) {
                        answer ++;
                    }
                }
            }
        }
        System.out.println(answer);
        return answer;
    }
}