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
    public ListNode ReverseList(ListNode head) {
        if(head == null) return null;
        ListNode newHead = head;
        if(head.next != null)
        {
            newHead = ReverseList(head.next);
            head.next.next = head;
            head.next = null;
        }
        return newHead;
    }
}
