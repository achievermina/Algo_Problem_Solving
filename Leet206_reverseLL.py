#Leet206 Iterative 
#08/09/2019

def reverseList(self, head):
        if not head or not head.next:
            return head
        
        cur = head
        prev = None
        
        while cur:
            nxt = cur.next
            cur.next= prev
            prev = cur
            cur = nxt
            
        return prev
            
        
