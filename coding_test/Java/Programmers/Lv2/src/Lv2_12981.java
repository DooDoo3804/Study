import java.util.ArrayList;

public class Lv2_12981 {
    public static void main(String[] args) {
        Solution12981 s = new Solution12981();
        int n = 3;
        String[] words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
        s.solution(n, words);

    }
}

class Solution12981 {
    public int[] solution(int n, String[] words) {
        ArrayList<String> wordsList = new ArrayList();
        int looseUser = 0;
        int userTurn = 0;

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            if (wordsList.size() == 0)
                wordsList.add(word);
            else {
                String lastWord = wordsList.get(wordsList.size()-1);
                if (lastWord.charAt(lastWord.length()-1) != word.charAt(0)) {
                    looseUser = i % n + 1;
                    userTurn = (int) i / n + 1;
                    break;
                }
                else if (wordsList.contains(words[i])) {
                    looseUser = i % n + 1;
                    userTurn = (int) i / n + 1;
                    break;
                }
                else
                    wordsList.add(word);
            }
        }

        int[] answer = {looseUser, userTurn};
        return answer;
    }
}