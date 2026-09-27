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
    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int leftDepth=1+solve(root->left);
        int rightDepth=1+solve(root->right);
        return max(leftDepth,rightDepth);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return solve(root);
    }
};