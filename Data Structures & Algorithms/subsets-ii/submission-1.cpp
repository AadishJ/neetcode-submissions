class Solution {
public:
    vector<vector<int>> ans;
    vector<int> n;
    vector<int> temp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums;
        sort(n.begin(),n.end());
        sol(0);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }

    void sol(int j){
        ans.push_back(temp);
        for(int i=j;i<n.size();i++){
               if (i > j && n[i] == n[i-1]) continue; 
                temp.push_back(n[i]);
                sol(i+1);
                temp.pop_back();
        }
    }
};
