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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *before = dummy;
        for (int i = 1 ; i < left ; i++) {
            before = before->next;
        }
        ListNode *prev = nullptr;
        ListNode *cur = before->next;
        for (int i = 0; i <= right - left ; i++) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* tail = before->next;
        before->next = prev;
        tail->next = cur;
        return dummy->next;
    }
};