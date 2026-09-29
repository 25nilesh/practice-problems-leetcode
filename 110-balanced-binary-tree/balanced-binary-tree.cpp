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
    int treeDepth(TreeNode* root){
        if(root==NULL) return 0;
        int leftDepth=1+treeDepth(root->left);
        int rightDepth=1+treeDepth(root->right);
        return max(leftDepth,rightDepth);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int lTree=treeDepth(root->left);
        int rTree=treeDepth(root->right);

        if(abs(lTree-rTree)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};