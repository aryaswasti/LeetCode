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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head2 = list2;
        ListNode* tail2 = list2;
        
        while(tail2->next != NULL){
            tail2 = tail2->next;
        }
        
        int count = 0;
        ListNode* ptr1 = list1;
        ListNode* remStart = NULL;
        ListNode* remEnd = NULL;
        
        while(ptr1->next != NULL){
            if(count == a-1){
                remStart = ptr1;
            } else if(count == b){
                remEnd = ptr1;
            } 
            count++;
            ptr1 = ptr1->next;
        }
        
        remStart->next = head2;
        tail2->next = remEnd->next;
        
        return list1;
    }
};