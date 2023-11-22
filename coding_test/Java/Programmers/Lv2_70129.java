public class Lv2_70129 {
    public static void main(String[] args) {
        Solution70129 sol = new Solution70129();
        String s = "110010101001";
        sol.solution(s);
    }
}

class Solution70129 {
    public int[] solution(String s) {
        int countZero = 0;
        int countChange = 0;


        while (!s.equals("1")) {
            int subCount = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0')
                    countZero += 1;
                else
                    subCount ++;
            }
            s = "";
            while (subCount != 0) {
                if (subCount % 2 == 1)
                    s = "1" + s;
                else
                    s = "0" + s;
                subCount /= 2;
            }
            countChange ++;
        }

        int[] answer = {countChange, countZero};
        System.out.println(answer[1]);
        return answer;
    }
}