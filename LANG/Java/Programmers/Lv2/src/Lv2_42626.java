import java.util.PriorityQueue;

public class Lv2_42626 {
    public static void main(String[] args) {
        Solution42626 s = new Solution42626();
        int[] scoville = {1, 2, 3, 9, 10, 12};
        int K = 7;
        s.solution(scoville, K);
    }
}


class Solution42626 {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for (int s : scoville) {
            pq.offer(s);
        }

        while (!pq.isEmpty()) {
            if (pq.size() == 1) {
                if (pq.peek() >= K) return answer;
                else return -1;
            }
            if (pq.peek() >= K) return answer;
            else {
                int target = pq.poll();
                int secondTarget = pq.poll();
                int result = target + secondTarget*2;
                pq.offer(result);
                answer ++;
            }
        }
        return answer;
    }
}