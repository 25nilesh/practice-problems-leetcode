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
    // int treeHeight(TreeNode* root){
    //     if(root==NULL) 
    //         return 0;
    //     int leftHeight=1+treeHeight(root->left);
    //     int rightHeight=1+treeHeight(root->right);
    //     return max(leftHeight,rightHeight);
    // }
    // int solve(TreeNode* root,int ans){
    //     if(root==NULL) return 0;

    //     int leftDepth=treeHeight(root->left);
    //     int rightDepth=treeHeight(root->right);
    //     ans=max(leftDepth+rightDepth,ans);
    //     int left=solve(root->left,ans);
    //     int right=solve(root->right,ans);
    //     ans=max({left,right,ans});
    //     return ans;

    // }
    int solve(TreeNode* root,int& ans){
        if(root==NULL) return 0;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        ans=max(left+right,ans);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        int result=solve(root,ans);
        return ans;
    }
};