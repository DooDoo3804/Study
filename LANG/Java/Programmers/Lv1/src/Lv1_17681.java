
public class Lv1_17681 {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[][] totalMap = new String[n][n];
        String[] answer = new String[n];
        for (int i=0; i<n; i++) {
            String lineNum1 = toBinary(n, arr1[i]);
            String lineNum2 = toBinary(n, arr2[i]);
            answer[i] = "";
            for (int j=0; j<n; j++) {
                if (lineNum1.charAt(j) == '1' || lineNum2.charAt(j) == '1') {
                    answer[i] += "#";
                }
                else {
                    answer[i] += " ";
                }
            }
        }
        return answer;
    }
    
    public String toBinary(int n, int m) {
        String subNum = "";
        String returnNum = "";
        while(m >= 1){
            if (m%2 == 0) {
                subNum += "0";
            }
            else {
                subNum += "1";
            }
            m = (int) m / 2;
        }
        for (int k=0; k<n-subNum.length(); k++) {
            returnNum += "0";
        }
        for (int k = subNum.length()-1; k>=0; k--) {
            returnNum += String.valueOf(subNum.charAt(k));
        }
        return returnNum;
    }
}
