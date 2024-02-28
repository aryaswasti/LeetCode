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
    int findBottomLeftValue(TreeNode* root) {
        //declare queue for BFS
        queue<TreeNode*> q;
        //store left most value of the level
        int val = root->val;
        
        //push root value in queue 
        q.push(root);
        
        //iterate on queue till its empty
        while(!q.empty()){
            //count all nodes on that level
            int count = q.size();
            //iterate on that level from left to right
            for(int i=0; i<count; i++){
                //get current element
                TreeNode* curr = q.front();
                q.pop();
                
                //if first element of level => assign it as left most val
                if(i == 0){
                    val = curr->val;
                }
                //push left node first(so it is pushed first into queue for next level)
                if(curr->left){
                    q.push(curr->left);
                }
                //push right node
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        //return left most element
        return val;
        
    }
};