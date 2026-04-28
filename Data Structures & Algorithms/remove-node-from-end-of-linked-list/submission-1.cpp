/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        int count = 0;
        while (fast != nullptr && count < n) {
            fast = fast->next;
            count++;
        }
        ListNode *slow = head, *prev = nullptr;
        while (fast != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (slow == head) return slow->next;
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
};
