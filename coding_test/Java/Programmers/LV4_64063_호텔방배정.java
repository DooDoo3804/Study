import java.io.*;
import java.util.*;

class Solution {
    
    static HashMap<Long, Long> hs = new HashMap<>();
    
    public long[] solution(long k, long[] room_number) {
        long[] answer = new long[room_number.length];
        
        for (int i = 0; i < room_number.length; i++) {
            long num = room_number[i];
            answer[i] = findNum(num);
        }
        
        return answer;
    }
    long findNum(long n) {
        if (!hs.containsKey(n)) {
            hs.put(n, n + 1);
            return n;
        }
        // 있
        long next = hs.get(n);
        long empty = findNum(next);
        hs.put(next, empty + 1);
        return empty;
    }
}