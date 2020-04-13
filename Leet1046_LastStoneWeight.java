import java.util.Collections;
import java.util.PriorityQueue;

public class Leet1046_LastStoneWeight {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for (int num : stones) {
            pq.add(num);
        }

        while(pq.size() > 1) {
            int first = pq.poll();
            int second = pq.poll();

            if(first == second) pq.add(0);
            else {
                pq.add(Math.abs(first-second));
            }
        }
        return pq.peek();
    }


}
