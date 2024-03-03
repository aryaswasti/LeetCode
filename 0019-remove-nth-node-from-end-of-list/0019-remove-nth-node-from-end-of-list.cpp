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
        //using dummy node that points to head provides prev node to head
        //this helps us to handle case where we have to remove head from the node
        //hence we don't have to use seperate logic for updating head node after removal 
        ListNode dummy(0);
        dummy.next = head;
        ListNode* first = &dummy;
        ListNode* second = &dummy;

        // Move both pointers until first reaches the end
        while (first->next != nullptr) {
            first = first->next;
            if (n <= 0)
                second = second->next;
            --n;
        }

        // Remove the nth node from the end
        ListNode* temp = second->next;
        second->next = second->next->next;
        delete temp;

        return dummy.next;
    }
};