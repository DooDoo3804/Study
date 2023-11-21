import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long x1 = Integer.parseInt(st.nextToken());
        long y1 = Integer.parseInt(st.nextToken());
        long x2 = Integer.parseInt(st.nextToken());
        long y2 = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        long x3 = Integer.parseInt(st.nextToken());
        long y3 = Integer.parseInt(st.nextToken());
        long x4 = Integer.parseInt(st.nextToken());
        long y4 = Integer.parseInt(st.nextToken());

        long t1 = CCW(x1, y1, x3, y3, x4, y4) * CCW(x2, y2, x3, y3, x4, y4);
        long t2 = CCW(x3, y3, x1, y1, x2, y2) * CCW(x4, y4, x1, y1, x2, y2);

        if (t1 <= 0 && t2 <= 0) {
            if((Math.min(x1, x2) <= Math.max(x3, x4)) && (Math.min(x3, x4) <= Math.max(x1, x2)) && (Math.min(y1, y2) <= Math.max(y3, y4)) && (Math.min(y3, y4) <= Math.max(y1, y2))) {
                System.out.println(1);
            } else System.out.println(0);
        }
        else System.out.println(0);
    }

    public static long CCW(long a1, long b1, long a2, long b2, long a3, long b3) {
        long temp = a1*b2 + a2*b3 + a3*b1;
        temp -= b1*a2 + b2*a3 + b3*a1;
        if (temp >0) return 1;
        else if (temp < 0) return -1;
        else return 0;
    }

}
