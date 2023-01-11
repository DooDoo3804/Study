import java.util.ArrayList;

public class Lv1_67256 {
    public static void main(String[] args) {
        Solution67256 s = new Solution67256();
        int[] numbers = {7,0,8,2,8,3,1,5,7,6,2};
        String hand = "left";
        s.solution(numbers, hand);
    }
}

class Solution67256 {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int[][] phoneMap = new int[4][3];
        ArrayList<CoordNum> nums = new ArrayList<CoordNum>();
        nums.add(new CoordNum(4,2));
        phoneMap[3][1] = 0;
        int num = 1;
        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                phoneMap[i][j] = num;
                nums.add(new CoordNum(i+1, j+1));
                num ++;
            }
        }
        nums.add(new CoordNum(4,1));
        nums.add(new CoordNum(4,3));
        int lPos = 10;
        int rPos = 11;
        ArrayList lNums = new ArrayList();
        ArrayList rNums = new ArrayList();
        lNums.add(1);
        lNums.add(4);
        lNums.add(7);
        rNums.add(3);
        rNums.add(6);
        rNums.add(9);

        for (int i : numbers) {
            if (lNums.contains(i)) {
                answer += "L";
                lPos = i;
            }
            else if (rNums.contains(i)) {
                answer += "R";
                rPos = i;
            }
            else {
                if (nums.get(i).distance(nums.get(lPos)) > nums.get(i).distance(nums.get(rPos))) {
                    answer += "R";
                    rPos = i;
                }
                else if (nums.get(i).distance(nums.get(lPos)) == nums.get(i).distance(nums.get(rPos))) {
                    if (hand.equals("right")) {
                        answer += "R";
                        rPos = i;
                    } else {
                        answer += "L";
                        lPos = i;
                    }
                } else {
                    answer += "L";
                    lPos = i;
                }
            }
        }
        System.out.println(answer);
        return answer;
    }
    private static class CoordNum {
        int xCoord;
        int yCoord;

        public CoordNum(int xCoord, int yCoord) {
            this.xCoord = xCoord;
            this.yCoord = yCoord;
        }

        public int distance(CoordNum q) {
            return Math.abs(this.xCoord-q.xCoord) + Math.abs(this.yCoord - q.yCoord);
        }
    }
}