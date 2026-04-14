/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null) return null;
        ListNode fast, slow, prev;
        fast = slow = head;
        int count = 0;
        while (fast != null && count < n) {
            fast = fast.next;
            count++;
        }
        prev = null;
        while (fast != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next;
        }
        if (slow == head) {
            return head.next;
        }
        prev.next = slow.next;
        slow.next = null;
        return head;
    }
}
