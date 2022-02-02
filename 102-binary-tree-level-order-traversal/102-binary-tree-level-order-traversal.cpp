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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> res;
        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        int level = q.size(), current = 0;
        
        while(q.size())
        {
            TreeNode* frontEle = q.front();
            if(frontEle->left)
                q.push(frontEle->left);
            if(frontEle->right)
                q.push(frontEle->right);
            
            arr.push_back(frontEle->val);
            q.pop();
            current++;
            if(current == level)
            {
                res.push_back(arr);
                arr.clear();
                level = q.size();
                current = 0;
            }
        }
        return res;
    }
};