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
    // int treeDepth(TreeNode* root){
    //     if(root==NULL) return 0;
    //     int leftDepth=1+treeDepth(root->left);
    //     int rightDepth=1+treeDepth(root->right);
    //     return max(leftDepth,rightDepth);
    // }
    int checkBalanced(TreeNode* root){
        if(root==NULL) return 0;
        
        int left=checkBalanced(root->left);
        int right=checkBalanced(root->right);
        
        if(abs(left-right)>1) return -1;
        if(left==-1 || right==-1) return -1;

        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        // if(root==NULL) return true;
        
        // int lDepth=treeDepth(root->left);
        // int rDepth=treeDepth(root->right);

        // if(abs(lDepth-rDepth)>1) return false;
        // return isBalanced(root->left) && isBalanced(root->right);
        int result=checkBalanced(root);
        return result == -1 ? false : true;
    }
};