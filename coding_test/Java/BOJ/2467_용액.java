import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        long[] arr = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Long.parseLong(st.nextToken());

        int left = 0;
        int right = n - 1;
        int min_l = 0;
        int min_r = 0;
        long min_sum = Long.MAX_VALUE;

        while (left < right) {
            long sub_sum = arr[left] + arr[right];
            if (Math.abs(sub_sum) < min_sum) {
                min_sum =Math.abs(sub_sum);
                min_l = left;
                min_r = right;
            }
            if (sub_sum >= 0) right--;
            else left++;
        }

        System.out.println(arr[min_l] + " " + arr[min_r]);
    }
}