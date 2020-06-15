import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;

class The_Comparator implements Comparator<Map.Entry<String, Integer>> {
    public int compare(Map.Entry<String, Integer> a, Map.Entry<String, Integer> b) {
        if (a.getValue() == b.getValue()) {
            return b.getKey().compareTo(a.getKey());
        }
        return a.getValue() - b.getValue();
    }
}


public class Leet692_TopKFrequentWords {

    public List<String> topKFrequent(String[] words, int k) {
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue(new The_Comparator());
        //Another option
//        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(
//                (a,b) -> a.getValue()==b.getValue() ? b.getKey().compareTo(a.getKey()) : a.getValue()-b.getValue()
//        );

        Map<String, Integer> m = new HashMap<>();
        for (String w : words) {
            m.put(w, m.getOrDefault(w, 0)+1);
        }

        for (Map.Entry<String, Integer> item : m.entrySet()) {
            pq.offer(item);
            if(pq.size() > k ) {
                pq.poll();
            }
        }

        List<String> res = new ArrayList<>();
        while (!pq.isEmpty()) {
            res.add(pq.poll().getKey());
        }
        Collections.reverse(res);
        return res;
    }


}


//WITHOUT SYNTAX - only LOGIC
//public List<String> topKFrequent(String[] words, int k) {
//    Map<String, int> m = new HashMap<>();
//    for (String w : words) {
//        entry = m.getOrDefault(w, 0);
//        entry.value()++;
//
//        if(pq.last().value() < entry.value()) {
//            pq.poplast();
//            pq.add(entry);
//        }
//    }
//
//    List<String> res = pq.EntryKey();
//    return res;
//
//}
//
//    private comparator(Map.Entry<String, int> a, Map.Entry<String, int> b) {
//        if(a.value() == b.value()) {
//            return a.key - b.keyl
//        }
//
//        return a.value - b.value;
//
//
//    }