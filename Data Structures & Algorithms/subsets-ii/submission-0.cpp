class Solution {
public:
    set<vector<int>> ans;
    vector<int> n;
    vector<int> temp;
    unordered_map<int,bool> mp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums;
        sort(n.begin(),n.end());
        sol(0);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }

    void sol(int j){
        ans.insert(temp);
        for(int i=j;i<n.size();i++){
            if(mp[i]) continue;
                mp[i]=true;
                temp.push_back(n[i]);
                sol(i+1);
                temp.pop_back();
                mp[i]=false;
        }
    }
};
