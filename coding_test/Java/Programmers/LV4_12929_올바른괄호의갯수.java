class Solution {
    public void cursor(String str, int left, int right, int n) {
        if (str.length() > 2 * n) return;
        if (str.length() == 2 * n) 
            if (checkCursor(str)) {
                answer++;
                return;
            }
        if (left < n) cursor(str + "(", left + 1, right, n);
        if (right < n) cursor(str + ")", left, right + 1, n);
    }
    
    public boolean checkCursor(String str) {
        int cnt = 0;
        for (char s : str.toCharArray()) {
            if (s == '(') cnt++;
            else if (s == ')') cnt--;
            if (cnt < 0) return false;
        }
        return true;
    }
        
    int answer = 0;  
    
    public int solution(int n) {
        
        cursor("", 0, 0, n);
        return answer;
    }
}