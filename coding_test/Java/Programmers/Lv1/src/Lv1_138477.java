import java.util.ArrayList;
import java.util.Collections;

public class Lv1_138477 {
    public static void main(String[] args) {
        Solution138477 s = new Solution138477();
        int k = 3;
        int[] score = {10, 100, 20, 150, 1, 100, 200};
        s.solution(k, score);
    }
}

class Solution138477 {
    public int[] solution(int k, int[] score) {
        ArrayList<ScoreStatus> scores = new ArrayList<ScoreStatus>();
        ArrayList<Integer> answer = new ArrayList<>();
        for (int s : score) {
            scores.add(new ScoreStatus(s));
            Collections.sort(scores);
            if (scores.size() < k) {
                answer.add(scores.get(0).score);
            }
            else
                answer.add(scores.get(scores.size()-k).score);
        }
        return answer.stream().mapToInt(i->i).toArray();
    }

    private static class ScoreStatus implements Comparable<ScoreStatus>{
        int score;
        public ScoreStatus(int score) {
            this.score = score;
        }

        @Override
        public int compareTo(ScoreStatus o) {
            return this.score - o.score;
        }
    }
}