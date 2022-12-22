import java.util.*;

public class Lv2_138476 {
    public static void main(String[] args) {
    Solution138476 s = new Solution138476();
    int k = 6;
    int[] tangerine = {1,2,3,1,2,3,3,1,1,1};
    s.solution(k, tangerine);
    }
}

class Solution138476 {
    public int solution(int k, int[] tangerine) {
        int answer = 0;
        HashMap<Integer, Integer> sizeCount = new HashMap<>();
        for (int i : tangerine) {
            if (sizeCount.containsKey(i)) sizeCount.put(i, sizeCount.get(i)+1);
            else sizeCount.put(i, 1);
        }
        List<Map.Entry<Integer, Integer>> everyList = new ArrayList<>(sizeCount.entrySet());
        everyList.sort(Map.Entry.comparingByValue());
        int count = 0;
        for (int index = 0; index<everyList.size(); index++) {
            if (count >= k) {
                return answer;
            }
            count += everyList.get(everyList.size()-1-index).getValue();
            answer ++;
        }

        return answer;
    }
}