/*
// Definition for a Node.
public class Node {
    public int val;
    public Node next;
    public Node random;
    
    public Node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
}
*/

public class Solution {
    public Node CopyRandomList(Node head) {
        Dictionary<Node, Node> oldToCopy = new Dictionary<Node, Node>();
        if(head == null) return null;
        Node cur = head;
        while(cur != null)
        {
            Node copy = new Node(cur.val);
            oldToCopy.Add(cur, copy);
            cur = cur.next;
        }

        cur = head;
        while(cur != null)
        {
            Node copy = oldToCopy[cur];
            if(cur.next != null)
                copy.next = oldToCopy[cur.next];
            if(cur.random != null)
                copy.random = oldToCopy[cur.random];
            cur = cur.next;
        }

        return oldToCopy[head];
    }
}
