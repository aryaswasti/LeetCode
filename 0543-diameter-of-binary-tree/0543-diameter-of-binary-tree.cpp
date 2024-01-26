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
        //BASE CONDITION
        if(root == nullptr){
            return 0; 
        }
        
        //HYPOTHESIS: solve left and right subtree
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        
        //INDUCTION
        //1. temp stores the max of(left subtree, right subtree) + 1(including current node as height)
        int temp = max(l, r) + 1;
        //2. calcuate diameter of current node
        int ans = max(temp, l + r + 1);
        //3. store the result in res
        res = max(res, ans);
        
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        return res-1;
    }
};