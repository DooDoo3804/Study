public class Lv2_12985 {
    public static void main(String[] args) {
        Solution12985 s = new Solution12985();
        int n = 8;
        int a = 4;
        int b = 7;
        s.solution(n, a, b);
    }
}

class Solution12985
{
    public int solution(int n, int a, int b)
    {
        int answer = 0;
        int A = Math.min(a, b);
        int B = Math.max(a, b);
        boolean flag = true;
        while (flag) {
            answer ++;
            for (int i = 0; i < n; i++) {
                if (i*2+1 == A && (i+1)*2 == B) {
                    flag = false;
                }
            }
            A = (int) (A+1) / 2;
            B = (int) (B+1) / 2;
        }
        System.out.println(answer);
        return answer;
    }
}