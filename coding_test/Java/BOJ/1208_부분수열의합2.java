import java.io.*;
import java.util.*;

public class Main {
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int n, s;
    static int[] nums;
    static ArrayList<Integer> left = new ArrayList<>();
    static ArrayList<Integer> right = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        nums = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) nums[i] = Integer.parseInt(st.nextToken());

        makeHalf(0, n/2, 0, left);
        makeHalf(n/2 , n, 0, right);

        Collections.sort(right);

        long answer = 0;
        for (int num : left) {
            int temp = s - num;
            int upper = upperBound(right, temp);
            int lower = lowerBound(right, temp);
            answer += (lower - upper);
        }
        if (s==0) answer--;
        System.out.println(answer);

    }

    private static void makeHalf(int i, int n, int c, ArrayList<Integer> arr) {
        if (i == n) {
            arr.add(c);
            return;
        }
        makeHalf(i + 1, n, c + nums[i], arr);
        makeHalf(i + 1, n, c, arr);
    }

    private static int upperBound(ArrayList<Integer> arr, int temp) {
        int left_index = 0;
        int right_index = arr.size() - 1;
        while (left_index < right_index) {
            int mid = (left_index + right_index) / 2;
            if (arr.get(mid) < temp) {
                left_index = mid + 1;
            } else right_index = mid;
        }
        return right_index;
    }

    private static int lowerBound(ArrayList<Integer> arr, int temp) {
        int left_index = 0;
        int right_index = arr.size() - 1;
        while (left_index < right_index) {
            int mid = (left_index + right_index) / 2;
            if (arr.get(mid) <= temp) {
                left_index = mid + 1;
            } else right_index = mid;
        }
        if (arr.get(left_index) == temp) left_index++;
        return left_index;
    }

}
