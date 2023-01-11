import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Collections;

public class Lv1_42889 {
    public static void main(String[] args) {
        Solution42889 s = new Solution42889();
//        int N = 5;
//        int[] stages = {2,1,2,6,2,4,3,3};
//        s.solution(N, stages);
        int N = 3;
        int[] stages = {1,2,3,4};
        s.solution(N, stages);
    }
}

class Solution42889 {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        ArrayList<Stage> list = new ArrayList<>();

        for (int stage = 1; stage <= N; stage++) {
            int notClearCnt = 0;
            int reachedCnt = 0;
            for (int i = 0; i < stages.length; i++) {
                if (stages[i] >= stage)
                    reachedCnt++;
                if (stages[i] == stage)
                    notClearCnt++;
            }
            if (reachedCnt == 0)
                list.add(new Stage(stage, 0));
            else
                list.add(new Stage(stage, (double) notClearCnt / reachedCnt));
        }

        Collections.sort(list);

        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i).stageIdx;
        }
        return answer;
    }
    private static class Stage implements Comparable<Stage> {
        int stageIdx;
        double failPercent;

        public Stage(int stageIdx, double failPercent) {
            this.stageIdx = stageIdx;
            this.failPercent = failPercent;
        }

        @Override
        public int compareTo(Stage o) {
            if (this.failPercent == o.failPercent)
                return this.stageIdx - o.stageIdx;
            else
                return Double.compare(o.failPercent, this.failPercent);
            }
        // sort할 때 필요한 부분
    }
}