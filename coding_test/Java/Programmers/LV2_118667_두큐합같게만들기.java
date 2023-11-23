import java.util.*;

class Solution {
    public long solution(int[] queue1, int[] queue2) {
        ArrayDeque<Integer> q1 = new ArrayDeque<>();
        ArrayDeque<Integer> q2 = new ArrayDeque<>();
        
        long answer = 0;
        long subSum = 0;
        long sum1 = 0;
        long sum2 = 0;
        long l = queue1.length + queue2.length;
        
        for (int i = 0; i < queue1.length; i++) {
            subSum += queue1[i];
            sum1 += queue1[i];
            q1.addLast(queue1[i]);
        }
        for (int i = 0; i < queue2.length; i++) {
            subSum += queue2[i];
            sum2 += queue2[i];
            q2.addLast(queue2[i]);
        }
        if (subSum % 2 == 1) return -1;
        subSum /= 2;
        
        while (sum1 != sum2 && answer <= 4 * l) {
            if (sum1 > sum2) {
                int num = q1.pollFirst();
                sum1 -= num;
                sum2 += num;
                q2.addLast(num);
            }else {
                int num = q2.pollFirst();
                sum1 += num;
                sum2 -= num;
                q1.addLast(num);
            }
            answer++;
        }
        if (answer >= 4 * l) answer = -1;
        return answer;
    }
}