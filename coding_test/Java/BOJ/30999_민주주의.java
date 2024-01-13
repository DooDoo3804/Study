import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int answer = 0;
        for (int i = 0 ; i < n; i++) {
            String input = br.readLine();
            int count = 0;
            for (char c : input.toCharArray()) {
                if (c == 'O') count++;
            }
            if (count > (m - 1) / 2) answer++;
        }
        System.out.println(answer);
    }
}
