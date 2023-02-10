/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public void ReorderList(ListNode head) {
        if(head == null || head.next == null) return;
        ListNode l1 = head, slow = head, fast = head, prev = null;
        while(fast != null && fast.next != null)
        {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = null;
        ListNode l2 = ReverseList(slow);
        MergeTwoLists(l1, l2);
    }
    ListNode ReverseList(ListNode head) {
        if(head == null || head.next == null) return head;
        ListNode tmp = ReverseList(head.next);
        head.next.next = head;
        head.next = null;
        return tmp;
    }
    void MergeTwoLists(ListNode l1, ListNode l2) {
        while(l1 != null)
        {
            ListNode l1_next = l1.next;
            ListNode l2_next = l2.next;
            l1.next = l2;
            if(l1_next == null) break;
            l2.next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
}
