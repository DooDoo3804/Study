// 맨 처음 풀이
// class Solution {
//     public int[][] solution(int[][] rc, String[] operations) {
//         int r = rc.length;
//         int c = rc[0].length;
//         int cnt = 0;
//         String preOps = "";
//         int[][] answer = new int[r][c];
        
//         for (String operation : operations) {
//             if (preOps.equals(operation)) cnt++;
//             else {
//                 if (preOps.equals("ShiftRow")) ShiftRow(rc, cnt, r, c);
//                 else Rotate(rc, cnt, r, c);
//                 cnt = 1;
//                 preOps = operation;
//             }
//         }
        
//         if (preOps.equals("ShiftRow")) ShiftRow(rc, cnt, r, c);
//         else Rotate(rc, cnt, r, c);
//         for (int i = 0; i < r; i++)
//             answer[i] = rc[i].clone();
        
//         return answer;
//     }
    
//     public void ShiftRow(int[][] rc, int cnt, int r, int c) {
//         int[][] tempRow = new int[r][c];
//         for (int i = 0; i < r; i++) tempRow[i] = rc[i].clone();
//         cnt %= (r);
//         if (cnt == 0) return;
//         for (int i = 0; i < r; i++) {
//             rc[(cnt + i) % r] = tempRow[i].clone();
//         }
//     }
    
//     public void Rotate(int[][] rc, int cnt, int r, int c) {
//         cnt %= ((r + c - 2) * 2);
//         if (cnt == 0) return;
//         int[] tempRow = new int[(r + c - 2) * 2];
//         int index = 0;
//         for (int i = 0; i < c; i++) {
//             tempRow[index] = rc[0][i];
//             index++;
//         }
//         for (int i = 1; i < r - 1; i++) {
//             tempRow[index] = rc[i][c - 1];
//             index++;
//         }
//         for (int i = 0; i < c; i++) {
//             tempRow[index] = rc[r - 1][c - 1 - i];
//             index++;
//         }
//         for (int i = 1; i < r - 1; i++) {
//             tempRow[index] = rc[r - 1 - i][0];
//             index++;
//         }

//         int[][] moves = {{0, 1},{1, 0},{0, -1},{-1, 0}};
//         int startX = 0;
//         int startY = 0;
//         int direction = -1;
//         while (cnt > 0) {
//             if (direction == -1){
//                 cnt -= (c - 1);
//                 startY = c - 1;
//                 if (cnt < 0) startY += cnt;
//             } else if (direction == 1) {
//                 cnt -= (c - 1);
//                 startY = 0;
//                 if (cnt < 0) startY -= cnt;
//             } else if (direction == 0) {
//                 cnt -= (r - 1);
//                 startX = r - 1;
//                 if (cnt < 0) startX += cnt;
//             } else if (direction == 2) {
//                 cnt -= (r - 1);
//                 startX = 0;
//                 if (cnt < 0) startX -= cnt;
//             }
//             direction++;
//         }

//         for (int i = 0; i < tempRow.length; i++) {
//             rc[startX][startY] = tempRow[i];
//             if (direction == 0) {
//                 if (startY == c - 1) direction++;
//             } else if (direction == 1) {
//                 if (startX == r - 1) direction++;
//             } else if (direction == 2) {
//                 if (startY == 0) direction++;
//             } else if (direction == 3) {
//                 if (startX == 0) direction = 0;
//             }
//             startX += moves[direction][0];
//             startY += moves[direction][1];
//         }
//     }
// }

import java.util.*;

class Solution {
    
    ArrayDeque<Integer> lList = new ArrayDeque<>();
    ArrayDeque<Integer> rList = new ArrayDeque<>();
    ArrayDeque<Integer>[] rows;
    int index = 0;
    
    public int[][] solution(int[][] rc, String[] operations) {
        int r = rc.length;
        int c = rc[0].length;
        rows = new ArrayDeque[r];
        
        for (int i = 0; i < r; i++) {
            rows[i] = new ArrayDeque<>();
            for (int j = 0; j < c; j++) {
                if (j == 0) lList.add(rc[i][j]);
                else if (j == c - 1) rList.add(rc[i][j]);
                else rows[i].add(rc[i][j]);
            }
        }
        
        int cnt = 0;
        String preOps = "";
        int[][] answer = new int[r][c];
        
        for (String operation : operations) {
            if (preOps.equals(operation)) cnt++;
            else {
                if (preOps.equals("ShiftRow")) ShiftRow(cnt, r, c);
                else Rotate(cnt, r, c);
                cnt = 1;
                preOps = operation;
            }
        }
        
        if (preOps.equals("ShiftRow")) ShiftRow(cnt, r, c);
        else Rotate(cnt, r, c);
        
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++) {
                if (j == 0) answer[i][j] = lList.pollFirst();
                else if (j == c - 1) answer[i][j] = rList.pollFirst();
                else {
                    answer[i][j] = rows[index].pollFirst();
                }
            }
            index++;
            if (index == r) index = 0;
        }
    
        return answer;
    }
    
    public void ShiftRow(int cnt, int r, int c) {
        while (cnt-- > 0) {
            lList.addFirst(lList.pollLast());
            rList.addFirst(rList.pollLast());
            if (index == 0) index = r;
            index--;
        }
    }
    
    public void Rotate(int cnt, int r, int c) {
        cnt %= ((r + c - 2) * 2);
        int i = (index + r - 1) % r;
        if (cnt == 0) return;
        
        while (cnt-- > 0) {
            rows[index].addFirst(lList.pollFirst());
            rList.addFirst(rows[index].pollLast());
            rows[i].addLast(rList.pollLast());
            lList.addLast(rows[i].pollFirst());
        }
        
    }
}