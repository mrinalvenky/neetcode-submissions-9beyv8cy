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
    public void reorderList(ListNode head) {
        // Find the midpoint
        ListNode fast, slow;
        slow = fast = head;
        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode list2 = slow.next;
        slow.next = null;
        // reverse list2
        ListNode cur = list2, prev = null;
        while(cur != null) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        list2 = prev;
        // Merge head and list2
        ListNode list1 = head;
        while(list2 != null) {
            ListNode first = list1.next;
            ListNode second = list2.next;
            list1.next = list2;
            list2.next = first;
            list1 = first;
            list2 = second;
        }
    }
}
