class LRUCache {
private:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, ListNode*> l_map;
    ListNode* head;
    ListNode* tail;
    int space;
    void add_node_front(ListNode *new_node) {
        head->next->prev = new_node;
        new_node->next = head->next;
        new_node->prev = head;
        head->next = new_node;
    }
    void rem_node(ListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;
    }
public:

    LRUCache(int capacity) {
        space = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!l_map.count(key)) return -1;
        ListNode *node = l_map[key];
        rem_node(node);
        add_node_front(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (l_map.count(key)) {
            ListNode* node = l_map[key];
            node->val = value;
            rem_node(node);
            add_node_front(node);
            return;
        }
        ListNode *new_node = new ListNode(key, value);
        add_node_front(new_node);
        l_map[key] = new_node;
        space--;
        if (space < 0) {
            ListNode *r_node = tail->prev;
            rem_node(r_node);
            l_map.erase(r_node->key);
            delete r_node;
            space++;
        }
    }
};
