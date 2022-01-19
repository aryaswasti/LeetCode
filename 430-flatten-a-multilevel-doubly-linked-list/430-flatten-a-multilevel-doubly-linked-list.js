/**
 * // Definition for a Node.
 * function Node(val,prev,next,child) {
 *    this.val = val;
 *    this.prev = prev;
 *    this.next = next;
 *    this.child = child;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var flatten = function(head) {
    let currentNode = head, pos = 1;
    
    while(currentNode)
        {
            if(currentNode.child == null)
                {
                    currentNode = currentNode.next;
                    pos++;
                }
            else
                {
                    let start = currentNode;
                    let end = currentNode.next;
                    currentNode.child.prev = currentNode;
                    currentNode.next = currentNode.child;
                    currentNode.child = null;
                    let sublist = currentNode.next;
                    
                    while(sublist.next != null)
                        {
                            sublist = sublist.next;
                        }
                    if(end != null)
                    {
                        sublist.next = end;
                        end.prev = sublist;   
                    }
                }
        }
    return head;
};