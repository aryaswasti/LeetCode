/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //both leaf node case(true)
        if(p==NULL && q==NULL){
            return true;
        //one leaf node one value(not equal => false)
        } else if(p==NULL || q==NULL){
            return false;
        //value of left node != value of right node(not equal => false)
        } else if(p->val != q->val){      
            return false;
        }
        //check for both left and both right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};