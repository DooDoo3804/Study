import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long[] liquid = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) liquid[i] = Long.parseLong(st.nextToken());

        Arrays.sort(liquid);

        int first_po = 0;
        int second_po = 0;
        int third_po = 0;
        long min_sum = Long.MAX_VALUE;

        for (int i = 0; i <= n - 3; i++) {
            int right = n - 1;
            int left = i + 1;
            while (left < right) {
                long sub_sum = liquid[i];
                long left_right_sum = liquid[left] + liquid[right];
                if (min_sum >  Math.abs(sub_sum + left_right_sum)) {
                    min_sum =  Math.abs(sub_sum + left_right_sum);
                    first_po = i;
                    second_po = left;
                    third_po = right;
                }
                if (sub_sum + left_right_sum > 0) right--;
                else left++;
            }
        }

        System.out.println(liquid[first_po] + " " + liquid[second_po] + " " + liquid[third_po]);
    }
}