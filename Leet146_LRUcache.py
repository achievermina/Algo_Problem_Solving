from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.cap= capacity;
        self.occupied =0;
        self.cache= collections.OrderedDict()

    def get(self, key: int) -> int:
        if key in self.cache:
            value = self.cache[key]
            self.cache.pop(key)  
            self.cache[key]=value
            return self.cache[key]
        else:
            return -1;

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.pop(key)  #or you can use self.cache.move_to_end(key) instead of deleting and inserting again
            self.cache[key]=value

        else:
            if(self.occupied>=self.cap):
                self.cache.popitem(last=False)
            self.cache[key] =value
            self.occupied+=1

                


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
