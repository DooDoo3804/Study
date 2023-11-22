import java.util.ArrayList;

public class Lv1_64061 {
    public static void main(String[] args) {
    Solution64061 s = new Solution64061();
    int[][] board = {{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1}};
    int[] moves = {1,5,3,5,1,2,1,4};
    s.solution(board, moves);
    }
}

class Solution64061 {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        ArrayList<Integer> basket = new ArrayList<Integer>();
        ArrayList<ArrayList<Integer>> newBoard = new ArrayList();
        for (int i = 0; i< board[0].length; i++) {
            ArrayList<Integer> subList = new ArrayList();
            for (int j = 0; j< board[0].length; j++) {
                subList.add(board[j][i]);
            }
            newBoard.add(subList);
        }
        for (int line : moves) {
            for (int i = 0; i< board.length; i++) {
                if (newBoard.get(line-1).get(i) != 0) {
                    basket.add(newBoard.get(line-1).get(i));
                    newBoard.get(line-1).set(i, 0);
                    if (basket.size() >= 2) {
                        if (basket.get(basket.size()-2) == basket.get(basket.size()-1)) {
                            basket.remove(basket.size()-1);
                            basket.remove(basket.size()-1);
                            answer += 2;
                        }
                    }
                    break;
                }
            }
        }
        return answer;
    }
}
