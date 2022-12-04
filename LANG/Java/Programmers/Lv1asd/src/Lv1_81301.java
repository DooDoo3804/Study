public class Lv1_81301 {
    public int solution(String s) {
        String[] engList = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        
        for (int i=0; i<10; i++) {
            s = s.replaceAll(engList[i], Integer.toString(i));
        }
        return Integer.parseInt(s);
    }
}
