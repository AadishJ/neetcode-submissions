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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        sol(root);
        return ans;
    }
    int sol(TreeNode* root) {
        if (!root) return 0;
        int l = max(0, sol(root->left));
        int r = max(0, sol(root->right));
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }
};
