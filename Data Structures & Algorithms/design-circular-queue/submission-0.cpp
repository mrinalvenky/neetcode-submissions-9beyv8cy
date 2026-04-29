class MyCircularQueue {
private:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;

        ListNode() : val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    };
    int size;
    ListNode *head, *tail;
public:
    
    MyCircularQueue(int k) {
        size = k;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        ListNode *new_node = new ListNode(value);
        tail->prev->next = new_node;
        new_node->prev = tail->prev;
        new_node->next = tail;
        tail->prev = new_node;
        size--;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        ListNode *del_node = head->next;
        del_node->next->prev = head;
        head->next = del_node->next;
        del_node->next = del_node->prev = nullptr;
        delete del_node;
        size++;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return head->next->val;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return (head->next == tail);
    }
    
    bool isFull() {
        return (size == 0);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */