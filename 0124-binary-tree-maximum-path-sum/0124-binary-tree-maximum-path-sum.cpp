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
    int solve(TreeNode* root, int& res){
        if(root == nullptr){
            return 0;
        }
        
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        
        int temp = max(root->val, root->val + max(l , r));
        int ans = max(temp, root->val + l + r);
        res = max(ans, res);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};