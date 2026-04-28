/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        unordered_map<Node*, Node*> new_node_map;
        Node *cur = head;
        while (cur != nullptr) {
            Node *new_node = new Node(cur->val);
            new_node_map[cur] = new_node;
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            Node *cur_new = new_node_map[cur];
            if (cur->next != nullptr) cur_new->next = new_node_map[cur->next];
            if (cur->random != nullptr) cur_new->random = new_node_map[cur->random];
            cur = cur->next;
        }
        return new_node_map[head];
    }
};
