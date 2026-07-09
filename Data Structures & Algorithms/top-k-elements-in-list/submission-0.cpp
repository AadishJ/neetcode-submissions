class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<unordered_set<int>> v(nums.size()+1);
        for(auto it: mp){
            v[it.second].insert(it.first);
        }
        for(int i=nums.size();i>=0;i--){
            if(!v[i].empty()){
                for(auto it: v[i]){
                    ans.push_back(it);
                    k--;
                    if(k==0) return ans;
                }
            }
        }
        return ans;
    }
};
