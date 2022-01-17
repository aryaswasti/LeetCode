/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    let current = head, pos = 1, reverse_list = null, start = null, tail = null, next = null;
    if(head.next == null || head == null || left == right)
        return head;
    else
        {
            while(current)
            {
                if(left == 1)
                    {
                        start = null;
                        tail = current;
                        while(pos <= right)
                            {
                                next = current.next;
                                current.next = reverse_list;
                                reverse_list = current;
                                current = next;
                                pos++;
                            }
                        //start.next = reverse_list;
                        tail.next = current;
                        return reverse_list;
                    }
                else if(pos == left-1)
                    {
                        start = current;
                        tail = current.next;
                    }
                else if(pos == left)
                    {
                        while(pos <= right)
                            {
                                next = current.next;
                                current.next = reverse_list;
                                reverse_list = current;
                                current = next;
                                pos++;
                            }
                        start.next = reverse_list;
                        tail.next = current;
                        return head;
                    }
                current = current.next;
                pos++;
            }
        }
};