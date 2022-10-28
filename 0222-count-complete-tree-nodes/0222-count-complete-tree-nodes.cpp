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
int getTreeHeight(TreeNode* root) {
    int height = 0;
    
    while(root->left != NULL) {
        height++;
        root = root->left;
    }
    return height;
}

bool nodeExists(TreeNode* root, int height, int toFind) {
    float left = 0;
    float right = pow(2, height) - 1;
    int count = 0, mid;
        
    while(count < height) {
        mid = ceil((left+right)/2);

        if(toFind >= mid) {
            root = root->right;
            left = mid;
        } else {
            root = root->left;
            right = mid-1;
        }
        count++;
    }
    return root != NULL;
}

int getBottomHalf(TreeNode* root, int height) {
    float left = 0;
    float right = pow(2, height) - 1;
    
    int toFind;
    
    while(left < right){
        toFind = ceil((left+right)/2);
        if(nodeExists(root, height, toFind))
            left = toFind;
        else    
            right = toFind-1;
    }
    return left;
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int height =  getTreeHeight(root);
        if(height == 0)
            return 1;
        
        int topHalf = pow(2,height)-1;
        int bottomHalf = getBottomHalf(root, height);
        return topHalf+bottomHalf+1;
    }
};