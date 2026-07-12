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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "N";
        string s;
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val)+",";
        while (!q.empty()) {
            int st = q.size();
            for(int i = 0;i<st;i++){
                if(q.front()->left){
                    s+=to_string(q.front()->left->val)+",";
                    q.push(q.front()->left);
                }else{
                    s+="N,";
                }
                if(q.front()->right){
                    s+=to_string(q.front()->right->val)+",";
                    q.push(q.front()->right);
                }else{
                    s+="N,";
                }
                q.pop();
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N") return nullptr;
        stringstream s(data);
        string temp;
        vector<TreeNode*> tree;
        while (getline(s, temp, ',')) {
            if (temp != "N")
                tree.push_back(new TreeNode(stoi(temp)));
            else
                tree.push_back(nullptr);
        }
        for(TreeNode* t: tree){
            if(t) cout << t->val << ' ';
            else cout << "N" << ' ';
        }
        queue<int> q;
        q.push(0);
        int next=1;
        while (!q.empty() && next<tree.size()) {
            int ind = q.front();
            q.pop();
            if(!tree[ind]) continue;
            tree[ind]->left=tree[next];
            q.push(next++);
            if(next<tree.size()){
            tree[ind]->right=tree[next];
            q.push(next++);
            }
        }
        return tree[0];
    }
};
