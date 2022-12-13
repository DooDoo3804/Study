public class Lv2_92335 {
    public static void main(String[] args) {
        Solution92335 s = new Solution92335();
        int n = 437674;
        int k = 3;
        s.solution(n, k);
    }
}

class Solution92335 {
    public int solution(int n, int k) {
        Number number = new Number(n, k);
        String[] nList = number.kNumber.split("0");
        int answer = 0;
        for (String s : nList) {
            if (!s.equals("") && !s.equals("1")) {
                int count = 0;
                for (long i = 2; i*i <= Long.parseLong(s); i++) {
                    if (Long.parseLong(s) % i == 0)
                        count++;
                }
                if (count == 0)
                    answer++;
            }
        }
        System.out.println(answer);
        return answer;
    }
    private static class Number {
        String kNumber;
        public Number(int n, int k) {
            String subString = "";
            while(n != 0) {
                subString = n % k + subString;
                n = n / k;
            }
            this.kNumber = subString;
        }
    }
}