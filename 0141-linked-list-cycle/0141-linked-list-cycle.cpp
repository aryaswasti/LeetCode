/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //Floyd’s slow and fast pointers
        ListNode* fast = head;
        ListNode* slow = head;
        
        // we will increment fast by 2 step and slow by 1 step
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            //fast and slow are at same address => linked list has a cycle in it.
            if(fast == slow){
                return true;
            }
        }
        
        // if fast pointer reaches to NULL this means no cycle.
        return false;
    }
};