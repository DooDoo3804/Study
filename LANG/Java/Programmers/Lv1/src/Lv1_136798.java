public class Lv1_136798 {
    public static void main(String[] args) {
        Solution136798 s = new Solution136798();
        int number = 10;
        int limit = 3;
        int power = 2;
        s.solution(number, limit, power);
    }
}


class Solution136798 {
    public int solution(int number, int limit, int power) {
        int totalWeapon = 0;
        int answer = 0;
        for (int j = 1; j <= number; j++) {
            Weapon w = new Weapon(j, limit);
            if (w.needPower > limit) {
                totalWeapon += power;
            }
            else
                totalWeapon += w.needPower;
        }
        answer = totalWeapon;
        System.out.println(answer);
        return answer;
    }

    private static class Weapon {
        int needPower;
        public Weapon(int number, int limit) {
            int subSum = 0;
            for (int i = 1; i*i <= number; i++) {
                if (i*i == number)
                    subSum ++;
                else if (number%i == 0) {
                    subSum += 2;
                }
            }
            this.needPower = subSum;
        }
    }
}