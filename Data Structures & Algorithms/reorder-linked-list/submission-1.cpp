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
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *list2 = slow->next, *list1 = head;
        slow->next = nullptr;
        // Reverse list2
        ListNode *prev = nullptr, *cur = list2;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode *revList = prev;
        // Merge list1 and revList
        while(list1 != nullptr && revList != nullptr) {
            ListNode *list1_next = list1->next;
            ListNode *rev_next = revList->next;
            list1->next = revList;
            revList->next = list1_next;
            list1 = list1_next;
            revList = rev_next;
        }
    }
};
