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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return d;
    }
     int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int lH = maxDepth(root->left);
        int rH = maxDepth(root->right);
        d = max(lH+rH,d);
        return max(lH,rH)+1;
    }
};
