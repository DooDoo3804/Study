public class Lv2_49993 {
    public static void main(String[] args) {
        Solution49993 s = new Solution49993();
        String skill = "CBD";
        String[] skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
        s.solution(skill, skill_trees);
    }
}

class Solution49993 {
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for (String skills : skill_trees) {
            char[] skillArray = skills.toCharArray();
            boolean flag = true;
            int index = 0;
            for (char c : skillArray) {
                for (int i = 0; i < skill.length(); i++) {
                    if (skill.charAt(i) == c) {
                        if (skill.charAt(index) == c) {
                            index++;
                            flag = true;
                            break;
                        } else {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag == false) break;
            }
            if (flag == true) {
                answer ++;
            }
        }
        System.out.println(answer);
        return answer;
    }
}