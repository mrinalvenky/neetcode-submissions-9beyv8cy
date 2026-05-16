struct Node {
    int key;
    Node *left;
    Node *right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};

class MyHashSet {
private:
    vector<Node*> data;
    int size = 1000;
public:
    MyHashSet() {
        data.resize(size, nullptr);
    }
    
    Node* insert(Node *root, int key) {
        if (root == nullptr) return new Node(key);
        Node *cur = root;
        while (cur) {
            if (key == cur->key) return root;
            if (key < cur->key) {
                if (cur->left) cur = cur->left;
                else {
                    cur->left = new Node(key);
                    return root;
                }
            } else {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = new Node(key);
                    return root;
                }
            }
        }
        return root;
    }
    void add(int key) {
        int hIdx = key % size;
        data[hIdx] = insert(data[hIdx], key);
    }
    
    Node* removeNode(Node* root, int key) {
        if (!root) return root;
        Node *cur = root;
        if (key < root->key) {
            root->left = removeNode(root->left, key);
        } else if (key > root->key) {
            root->right = removeNode(root->right, key);
        } else {
            // no children
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            // Find inorder successor and swap
            Node *cur = root->right;
            while (cur->left) cur = cur->left;
            root->key = cur->key;
            root->right = removeNode(root->right, cur->key);
        }
        return root;
    }

    void remove(int key) {
        int hIdx = key % size;
        data[hIdx] = removeNode(data[hIdx], key);
    }
    
    bool check(Node *root, int key) {
        if (!root) return false;
        Node *cur = root;
        while (cur) {
            if (cur->key == key) return true;
            else if (cur->key > key) cur = cur->left;
            else cur = cur->right;
        }
        return false;
    }
    bool contains(int key) {
        int hIdx = key % size;
        return check(data[hIdx], key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */