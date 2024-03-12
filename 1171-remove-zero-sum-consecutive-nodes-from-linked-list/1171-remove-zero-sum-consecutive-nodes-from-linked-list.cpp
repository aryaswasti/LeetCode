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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        
        while (left != nullptr) {
            int prefixSum = 0;
            ListNode* right = left->next;

            while (right != nullptr) {
                // Add end's value to the prefix sum
                prefixSum += right->val;
                // Delete zero sum consecutive sequence 
                // by setting node before sequence to node after
                if (prefixSum == 0) {
                    left->next = right->next;
                }
                right = right->next;
            }

            left = left->next;
        }
        return dummy->next;
    }
};