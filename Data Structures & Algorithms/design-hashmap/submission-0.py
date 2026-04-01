class Node:
    def __init__(self, key: int, value: int):
        self.key = key
        self.value = value
        self.next = None

class MyHashMap:

    def __init__(self):
        self.h_arr = [Node(0,0) for i in range(10000)]

    def put(self, key: int, value: int) -> None:
        idx = key % (len(self.h_arr))
        cur = self.h_arr[idx]
        while cur.next:
            if cur.next.key == key:
                cur.next.value = value
                return
            cur = cur.next
        cur.next = Node(key, value)

    def get(self, key: int) -> int:
        idx = key % (len(self.h_arr))
        cur = self.h_arr[idx]
        while cur.next:
            if cur.next.key == key:
                return cur.next.value
            cur = cur.next
        return -1

    def remove(self, key: int) -> None:
        idx = key % (len(self.h_arr))
        cur = self.h_arr[idx]
        while cur.next:
            if cur.next.key == key:
                cur.next = cur.next.next
                return 
            cur = cur.next


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)