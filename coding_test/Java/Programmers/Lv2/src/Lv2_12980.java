import java.util.Stack;

public class Lv2_12980 {
    public static void main(String[] args) {
        Solution12980 s = new Solution12980();
        int n = 5000;
        s.solution(n);
    }
}

class Solution12980 {
    public int solution(int n) {
        Stack<Integer> dStack = new Stack<>();
        dStack.push(0);
        dStack.push(1);
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                dStack.push(Math.min(dStack.get(i/2), dStack.peek()+1));
            }
            else dStack.push(dStack.peek()+1);
        }
        System.out.println(dStack.peek());
        return dStack.peek();

//        int ans = 0;
//        while(n!=0){	//n이 0이 될때까지 반복을 해준다.
//            if(n%2==0){	//2로 나눴을때 0이라면 점프를
//                n/=2;
//            }else{	//홀수 일 경우에는 -1만큼 에너지를 사용해 준다.
//                n--;
//                ans++;
//            }
//        }
//        return ans;

//        이게 더 효율이 좋은 코드
//        stack을 통해 데이터를 가지고 가는 것은 메모리 초과를 야기
    }
}