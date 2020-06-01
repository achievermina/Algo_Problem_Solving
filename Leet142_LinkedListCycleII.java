import java.util.HashSet;

public class Leet142_LinkedListCycleII {
    public ListNode detectCycle(ListNode head) {

        Set<ListNode> visited = new HashSet<ListNode>();
        ListNode cur = head;
        while (cur != null) {
            if(visited.contains(cur))
                return cur;

            visited.add(cur);
            cur = cur.next;
        }

        return null;




    }
}
