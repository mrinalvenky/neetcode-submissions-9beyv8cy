class Node {
    int val;
    Node next;
    Node prev;

    public Node(int val) {
        this.val = val;
        next = null;
        prev = null;
    }
}

class Deque {
    private Node head;
    private Node tail;

    public Deque() {
        Node dummyHead = new Node(-1);
        Node dummyTail = new Node(-1);
        head = dummyHead;
        tail = dummyTail;
        head.next = tail;
        tail.prev = head;
    }

    public boolean isEmpty() {
        return this.head.next == this.tail;
    }

    public void append(int value) {
       Node newNode = new Node(value);
       Node prev = tail.prev;
       newNode.next = tail;
       tail.prev = newNode;
       prev.next = newNode;
       newNode.prev = prev;
    }

    public void appendleft(int value) {
        Node newNode = new Node(value);
        Node cur = head.next;
        newNode.prev = head;
        head.next = newNode;
        cur.prev = newNode;
        newNode.next = cur;
    }

    public int pop() {
        if (isEmpty()) {
            return -1;
        }
        Node cur = tail.prev;
        tail.prev = cur.prev;
        cur.prev.next = tail;
        return cur.val;
    }

    public int popleft() {
        if (isEmpty()) {
            return -1;
        }
        Node cur = head.next;
        head.next = cur.next;
        cur.next.prev = head;
        return cur.val;
    }
}
