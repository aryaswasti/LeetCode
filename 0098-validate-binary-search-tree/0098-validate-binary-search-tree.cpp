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

bool DFS(TreeNode* node, long long int lower, long long int higher)
{
    if(lower >= node->val || higher <= node->val) 
        return false;
    
    if(node->left) {
        if(!DFS(node->left, lower, node->val))
            return false;
    }
    
    if(node->right) {
        if(!DFS(node->right, node->val, higher))
            return false;
    }
    
    return true;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        return DFS(root, LLONG_MIN, LLONG_MAX);
    }
};