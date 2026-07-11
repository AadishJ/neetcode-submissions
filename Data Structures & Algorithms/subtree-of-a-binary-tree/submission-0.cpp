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
    bool ans = false;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        tr(root,subRoot);
        return ans;
    }
    void tr(TreeNode* root, TreeNode* subRoot){
        if(ans) return;
        if(!root) return;
        tr(root->right,subRoot);
        tr(root->left,subRoot);
        if(isSameTree(root,subRoot)) ans=true;
    }
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return true;
        }

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
