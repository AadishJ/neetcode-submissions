class Solution {
public:
    int sum=0;
    vector<int> temp;
    set<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sol(0,nums,target);
        vector<vector<int>> p(ans.begin(),ans.end());
        return p;
    }
    void sol(int i,vector<int>& nums, int target){
        if(i>=nums.size() || sum>target) return;
        if(sum==target){
            ans.insert(temp);
        }
        sum+=nums[i];
        temp.push_back(nums[i]);
        sol(i,nums,target);
        temp.pop_back();
        sum-=nums[i];
        sol(i+1,nums,target);
    }
};
