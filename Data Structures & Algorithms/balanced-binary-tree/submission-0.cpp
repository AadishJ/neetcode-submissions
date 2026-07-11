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
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root){
        if(!ans) return 0;
        if(!root) return 0;
        int lH = dfs(root->left);
        int rH = dfs(root->right);
        if(abs(lH-rH)>1) ans=false;
        return max(lH,rH)+1;
    }
};
