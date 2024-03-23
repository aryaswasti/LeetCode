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
    void reorderList(ListNode* head) {
        vector<int> val;
        
        ListNode* iter = head;
        while(iter != NULL){
            val.push_back(iter->val);
            iter = iter->next;
        }
        
        int left = 0;
        int right = val.size()-1;
        int cnt = 0;
        iter = head;
        
        while(iter != NULL && left<=right){
            if(cnt%2 == 0){
                iter->val = val[left];
                left++;
            } else {
                iter->val = val[right];
                right--;
            }
            
            cnt++;
            iter = iter->next;
        }
    }
};