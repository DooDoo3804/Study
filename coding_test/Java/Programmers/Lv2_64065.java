import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Lv2_64065  {
    public static void main(String[] args) {
        Solution64065 sol = new Solution64065();
        String s = "{{123}}";
        sol.solution(s);

    }
}

class Solution64065 {
    public int[] solution(String s) {
        ArrayList<Integer> nums = new ArrayList<>();
        ArrayList<Tuple> numsTuple = new ArrayList<>();
        String subString = "";
        for (Character c : s.toCharArray()) {
            if (c != '{') {
                if (c == '}') {
                    if (!nums.isEmpty() || subString != "") {
                        nums.add(Integer.parseInt(subString));
                        subString = "";
                        numsTuple.add(new Tuple(nums));
                        nums.clear();
                    }
                } else if (c == ',') {
                    if (subString != "") {
                        nums.add(Integer.parseInt(subString));
                        subString = "";
                    }
                } else{
                    subString += Character.toString(c);
                }
            }
        }
        Collections.sort(numsTuple);
        ArrayList<Integer> answer = new ArrayList();

        for (Tuple t : numsTuple) {
            for (int i : t.numTuple) {
                if (!answer.contains(i))
                    answer.add(i);
            }
        }

        return answer.stream().mapToInt(i->i).toArray();
    }


    private static class Tuple implements Comparable<Tuple> {
        ArrayList<Integer> numTuple = new ArrayList<>();

        public Tuple (ArrayList nums) {
            for (int i = 0; i < nums.size(); i++) {
                this.numTuple.add((Integer) nums.get(i));
            }
        }
        @Override
        public int compareTo(Tuple o) {
            return this.numTuple.size() - o.numTuple.size();
        }
    }
}