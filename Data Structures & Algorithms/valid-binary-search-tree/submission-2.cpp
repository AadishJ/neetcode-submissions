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
    bool ans=true;
    bool isValidBST(TreeNode* root) {
       sol(root,INT_MIN,INT_MAX);
       return ans;
    }
    void sol(TreeNode* root, int mini, int maxi){
        if(!root) return;
        if(!ans) return;
        if(root->val<=mini || root->val>=maxi) {
            ans=false;
        }
        sol(root->left,mini,min(root->val,maxi));
        sol(root->right,max(mini,root->val),maxi);
    }
};
