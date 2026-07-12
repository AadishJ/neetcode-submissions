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
    unordered_map<int, int> in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) in[inorder[i]] = i;
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps > pe || is > ie) return nullptr;
        TreeNode* root = new TreeNode(preorder[ps]);
        int inInd = in[preorder[ps]];
        int leftSize = inInd-is;
        int rightSize = ie-inInd;
        root->left = build(preorder,inorder,ps+1,ps+leftSize,is,is+leftSize);
        root->right = build(preorder,inorder,ps+leftSize+1,pe,inInd+1,inInd+rightSize);
        return root;
    }
};
