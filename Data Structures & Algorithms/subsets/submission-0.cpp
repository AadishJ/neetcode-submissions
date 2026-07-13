class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        sol(0,nums);
        return ans;
    }
    void sol(int i,vector<int>& nums){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        sol(i+1,nums);
        temp.pop_back();
        sol(i+1,nums);
    }
};
