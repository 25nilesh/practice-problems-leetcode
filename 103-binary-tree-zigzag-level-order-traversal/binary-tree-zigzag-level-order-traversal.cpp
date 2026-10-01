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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> qu;
        vector<vector<int>> result;
        qu.push(root);
        while(!qu.empty()){
            int sz=qu.size();
            vector<int> temp;
            while(sz--){
                TreeNode* curr=qu.front();
                qu.pop();
                temp.push_back(curr->val);
                if(curr->left) qu.push(curr->left);
                if(curr->right) qu.push(curr->right);
            }
            result.push_back(temp);
        }
        for(int i=0;i<result.size();i++){
            if(i&1) reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};