class HashNode {
    int key;
    int val;
    HashNode next;

    public HashNode(int key, int val) {
        this.key = key;
        this.val = val;
        next = null;
    }
}
class HashTable {
    private HashNode[] hTable;
    private int capacity;
    private int size;

    private int hashFunc(int key) {
        return Math.abs(key) % capacity;
    }

    public HashTable(int capacity) {
        this.capacity = capacity;
        hTable = new HashNode[capacity];
    }

    public void insert(int key, int value) {
        int idx = hashFunc(key);
        HashNode cur = hTable[idx];
        while (cur != null) {
            if (cur.key == key) {
                cur.val = value;
                return;
            }
            cur = cur.next;
        }
        HashNode newNode = new HashNode(key, value);
        newNode.next = hTable[idx];
        hTable[idx] = newNode;
        size++;
        if ((double) this.size / this.capacity >= 0.5) {
            this.resize();
        }
    }

    public int get(int key) {
        int idx = hashFunc(key);
        HashNode cur = hTable[idx];
        while (cur != null) {
            if (cur.key == key) {
                return cur.val;
            }
            cur = cur.next;
        }
        return -1;
    }

    public boolean remove(int key) {
        int idx = hashFunc(key);
        HashNode cur = hTable[idx];
        HashNode prev = null;
        while (cur != null) {
            if (cur.key == key) {
                if (prev == null) {
                    hTable[idx] = cur.next;
                } else {
                    prev.next = cur.next;
                }
                size--;
                return true;
            }
            prev = cur;
            cur = cur.next;
        }
        return false;
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }

    public void resize() {
        int oldCapacity = capacity;
        capacity = capacity * 2;
        HashNode[] oldTable = hTable;
        hTable = new HashNode[capacity];
        size = 0;

        for (int i = 0; i < oldCapacity; i++) {
            HashNode node = oldTable[i];
            while (node != null) {
                insert(node.key, node.val);
                node = node.next;
            }
        }
    }
}