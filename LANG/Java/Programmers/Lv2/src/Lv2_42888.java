import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lv2_42888 {
    public static void main(String[] args) {
        Solution42888 s = new Solution42888();
        String[] record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        s.solution(record);
    }
}

class Solution42888 {
    public String[] solution(String[] record) {
        ArrayList<User> userList = new ArrayList<>();
        Map<String, String> userInfo = new HashMap<>();
        for (String s : record) {
            String[] splitS = s.split(" ");
            String state = splitS[0];
            String userId = splitS[1];
            String userName= splitS.length==2? null: splitS[2];
            if (state.equals("Enter")) {
                userInfo.put(userId, userName);
                userList.add(new User(state, userId));
            } else if (state.equals("Leave")) {
                userList.add(new User(state, userId));
            } else if (state.equals("Change")) {
                userInfo.put(userId, userName);
            }
        }
        String[] answer = new String[userList.size()];
        for (int i = 0; i < userList.size(); i++) {
            if (userList.get(i).state.equals("Enter"))
                answer[i] = userInfo.get(userList.get(i).userId)+"님이 들어왔습니다.";
            else if (userList.get(i).state.equals("Leave"))
                answer[i] = userInfo.get(userList.get(i).userId)+"님이 나갔습니다.";
        }
        return answer;
    }

    private static class User{
        String userId;
        String state;
        public User(String state, String userId) {
            this.state = state;
            this.userId = userId;
        }
    }
}