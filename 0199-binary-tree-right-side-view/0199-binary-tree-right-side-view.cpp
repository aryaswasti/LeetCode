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

// BFS solution
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if(!root) return {};
        
//         vector<int> res;
//         queue<TreeNode*> q;
//         q.push(root);
//         int level = q.size(), ele = 0;
        
//         while(q.size())
//         {
//             TreeNode* frontEle = q.front();
            
//             if(frontEle->left)
//                 q.push(frontEle->left);
//             if(frontEle->right)
//                 q.push(frontEle->right);
            
//             q.pop();
//             ele++;
            
//             if(level == ele)
//             {
//                 res.push_back(frontEle->val);
//                 level = q.size();
//                 ele = 0;
//             }
//         }
//         return res;
//     }
// };

//DFS solution
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int> &res)
    {
        if(!root) return;

        if(level >= res.size())
            res.push_back(root->val);
        
        if(root->right)
            dfs(root->right, level+1, res);
        if(root->left)
            dfs(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {        
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};