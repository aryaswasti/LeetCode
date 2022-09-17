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
        if(!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        int level = q.size();
        int current = 0;
        
        vector<vector<int>> ans;
        vector<int> arr;
        
        while(q.size())
        {
            TreeNode* firstEle = q.front();
            if(firstEle->left)
                q.push(firstEle->left);
            if(firstEle->right)
                q.push(firstEle->right);
            
            current++;
            arr.push_back(firstEle->val);
            q.pop();
            if(current == level)
            {
                ans.push_back(arr);
                arr.clear();
                current = 0;
                level = q.size();
            }
        }
        return ans;
    }
};