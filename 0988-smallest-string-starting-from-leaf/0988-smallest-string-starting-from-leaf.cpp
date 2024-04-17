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
    
    string smString = "";    

    private:
        void dfs(TreeNode* node, string str){
            if(node == nullptr){
                return;
            }

            str=char(node->val+97)+str;
            
            if(!node->left && !node->right){
                if(smString == "" or smString > str){
                    smString = str;
                }
            }

            dfs(node->left, str);
            dfs(node->right, str);
        }
    public:
        string smallestFromLeaf(TreeNode* root) {
            dfs(root, "");
            return smString;
        }
    };