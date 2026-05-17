class MyHashMap {
private:
    struct Node {
        int key;
        int val;
        Node *next;
        Node() : next(nullptr) {}
        Node(int k, int v) : key(k), val(v), next(nullptr) {}
    };
    vector<Node*> mp_;
    size_t size_;
public:
    MyHashMap() {
        size_ = 1000;
        mp_.resize(size_, nullptr);
    }
    uint32_t hash_key(int key) {
        return key % size_;
    }
    
    void put(int key, int value) {
        int k = hash_key(key);
        if (mp_[k] == nullptr) {
            mp_[k] = new Node(key, value);
            return;
        }
        Node *cur = mp_[k], *prev = nullptr;
        while(cur) {
            if (cur->key == key) {
                cur->val = value;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        if (prev) {
            prev->next = new Node(key, value);
        }
    }
    
    int get(int key) {
        int k = hash_key(key);
        Node *cur = mp_[k];
        while(cur) {
            if (cur->key == key) {
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int k = hash_key(key);
        if (mp_[k] == nullptr) {
            return;
        }
        Node *cur = mp_[k], *prev = nullptr;
        while(cur) {
            if (cur->key == key) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (!cur) return;
        if (prev) {
            prev->next = cur->next;
            cur->next = nullptr;
            delete cur;
        } else {
            mp_[k] = mp_[k]->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */