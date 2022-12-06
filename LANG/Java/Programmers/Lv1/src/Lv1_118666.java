
public class Lv1_118666 {
    public static void main(String[] args) {
        Solution118666 s = new Solution118666();
        String[] survey = {"AN", "CF", "MJ", "RT", "NA"};
        int[] choices = {5, 3, 2, 7, 5};
        s.solution(survey, choices);
    }
}

class Solution118666 {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int score1 = 0;
        int score2 = 0;
        int score3 = 0;
        int score4 = 0;

        for (int i = 0; i<survey.length; i++) {
            UserServey us = new UserServey(survey[i].charAt(0), survey[i].charAt(1), choices[i]);
            if (us.status == 'R' || us.status == 'T') {
                if (us.status == 'R')
                    score1 += us.score;
                else
                    score1 -= us.score;
            }
            else if (us.status == 'C' || us.status == 'F') {
                if (us.status == 'C')
                    score2 += us.score;
                else
                    score2 -= us.score;
            }
            else if (us.status == 'J' || us.status == 'M') {
                if (us.status == 'J')
                    score3 += us.score;
                else
                    score3 -= us.score;
            }
            else if (us.status == 'A' || us.status == 'N') {
                if (us.status == 'A')
                    score4 += us.score;
                else
                    score4 -= us.score;
            }
        }
        if (score1 >= 0)
            answer += "R";
        else
            answer += "T";
        if (score2 >= 0)
            answer += "C";
        else
            answer += "F";
        if (score3 >= 0)
            answer += "J";
        else
            answer += "M";
        if (score4 >= 0)
            answer += "A";
        else
            answer += "N";

        return answer;
    }

    private static class UserServey {
        char status;
        int score;

        public UserServey (char pre, char stu, int check) {
            this.score = Math.abs(4-check);
            if (check < 4)
                this.status = pre;
            else if (check > 4)
                this.status = stu;
            else
                this.status = '0';
        }
    }
}