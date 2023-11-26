import java.io.*;
import java.util.*;

class Solution {
    
    public int solution(int[] food_times, long k) {
        int answer = 0;
        
        class Food implements Comparable<Food>{
            int index, time;
            
            Food (int index, int time) {
                this.index = index; this.time = time;
            }
            public int getIndex() {return this.index;}
            @Override
            public int compareTo(Food o) {
                return Integer.compare(this.time, o.time);
            }
        }
        
        PriorityQueue<Food> pq = new PriorityQueue<>();
        long subSum = 0;
        for (int i = 0; i < food_times.length; i++) {
            int ft = (int) food_times[i];
            subSum += ft;
            pq.offer(new Food(i + 1, ft));
        }
        
        if (subSum <= k) return -1;
        
        long totalTime = 0;
        long nowTime = 0;
        long preTime = 0;
        long length = food_times.length;
        
        while((totalTime + (pq.peek().time - preTime) * length) <= k) {
            int now = pq.poll().time;
            totalTime += (now - preTime) * length;
            preTime = now;
            length--;
        }
        
        ArrayList<Food> arr = new ArrayList<>();
        while (!pq.isEmpty()) {
            arr.add(pq.poll());
        }
        
        Collections.sort(arr, new Comparator<Food>(){
            @Override
            public int compare(Food a, Food b) {
                return Integer.compare(a.index, b.index);
            }
        });
        answer = arr.get((int) ((k - totalTime) % length)).index;
        
        return answer;
    }
}