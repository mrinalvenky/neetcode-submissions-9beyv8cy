class Node {
    int val;
    Node next;
    public Node(int val) {
        this.val = val;
    }
}

class LinkedList {
    private Node head;
    private Node tail;

    public LinkedList() {
        Node dummy = new Node(-1);
        head = dummy;
        tail = dummy;
    }

    public int get(int index) {
        Node cur = head.next;
        int idx = 0;
        while (cur != null && idx < index) {
            cur = cur.next;
            idx += 1;
        }
        if (cur != null) {
            return cur.val;
        }
        return -1;
    }

    public void insertHead(int val) {
        Node newNode = new Node(val);
        Node nd  = head.next;
        head.next = newNode;
        newNode.next = nd;
        if (head == tail) {
            tail = newNode;
        }
    }

    public void insertTail(int val) {
        Node newNode = new Node(val);
        tail.next = newNode;
        tail = newNode;
    }

    public boolean remove(int index) {
        Node cur = head.next;
        Node prev = head;
        int idx = 0;
        while (cur != null && idx < index) {
            prev = cur;
            cur = cur.next;
            idx += 1;
        }
        if (cur != null) {
            prev.next = cur.next;
            if (cur == tail) {
                tail = prev;
            }
            return true;
        }
        return false;
    }

    public ArrayList<Integer> getValues() {
        ArrayList<Integer> arrList = new ArrayList<>();
        Node cur = head.next;
        while (cur != null) {
            arrList.add(cur.val);
            cur = cur.next;
        }
        return arrList;
    }
}
