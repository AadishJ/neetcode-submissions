class Solution {
public:
    int sum=0;
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sol(0,nums,target);
        return ans;
    }
    void sol(int i,vector<int>& nums, int target){
        if(i>=nums.size() || sum>target) return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        sum+=nums[i];
        temp.push_back(nums[i]);
        sol(i,nums,target);
        temp.pop_back();
        sum-=nums[i];
        sol(i+1,nums,target);
    }
};
