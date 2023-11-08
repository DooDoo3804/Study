import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        class Stuff implements Comparable{
            int measure; int value;
            Stuff (int m, int v) {
                this.measure = m;
                this.value = v;
            }
            @Override
            public int compareTo(Object o) {
                Stuff a = (Stuff) o;
                return this.measure - a.measure;
            }
        }

        Stuff[] stuffs = new Stuff[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(bf.readLine());
            int m = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            stuffs[i] = new Stuff(m, v);
        }

        Arrays.sort(stuffs);

        ArrayList<Integer> bags = new ArrayList<Integer>();
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(bf.readLine());
            int c = Integer.parseInt(st.nextToken());
            bags.add(c);
        }
        Collections.sort(bags);
        long answer = 0;
        int index = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < k; i++) {
            while (index < n && stuffs[index].measure <= bags.get(i)) {
                pq.offer(stuffs[index++].value);
            }
            if (!pq.isEmpty()) answer += pq.poll();
        }
        System.out.println(answer);
    }

}
