class Solution {
public:
    vector<int> n;
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums;
        sol(0);
        return ans;
    }
    void sol(int ind){
        if(ind>=n.size()) {ans.push_back(n);return;}
        for(int i=ind;i<n.size();i++){
            swap(n[i],n[ind]);
            sol(ind+1);
            swap(n[i],n[ind]);
        }
    }
};
