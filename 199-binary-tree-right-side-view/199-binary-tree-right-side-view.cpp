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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int level = q.size(), ele = 0;
        
        while(q.size())
        {
            TreeNode* frontEle = q.front();
            
            if(frontEle->left)
                q.push(frontEle->left);
            if(frontEle->right)
                q.push(frontEle->right);
            
            if(ele == level - 1)
                res.push_back(frontEle->val);
            
            q.pop();
            ele++;
            
            if(level == ele)
            {
                level = q.size();
                ele = 0;
            }
        }
        return res;
    }
};