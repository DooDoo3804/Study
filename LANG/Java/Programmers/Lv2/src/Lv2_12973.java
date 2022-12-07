import java.util.Stack;
public class Lv2_12973 {
    public static void main(String[] args) {
        Solution12973 sol = new Solution12973();
        String s = "asdfghjkllkjhgfdsaqweewqzxccxz";
        sol.solution(s);
    }
}

class Solution12973
{
    public int solution(String s) {
        int answer = 0;
        Stack<Character> charStack = new Stack<>();

        for (char c : s.toCharArray()) {
            if (!charStack.isEmpty() && charStack.peek() == c)
                charStack.pop();
            else
                charStack.push(c);
        }
        return charStack.isEmpty() ? 1 : 0;
    }
}