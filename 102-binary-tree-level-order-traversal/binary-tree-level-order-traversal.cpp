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
        queue<TreeNode*> qu;
        vector<vector<int>> result;
        if(root==NULL) return result;
        qu.push(root);
        vector<int> temp;
        while(!qu.empty()){
            int sz=qu.size();
            temp={};
            while(sz--){
                TreeNode* curr=qu.front();
                qu.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL) qu.push(curr->left);
                if(curr->right!=NULL) qu.push(curr->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};