class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> permute(vector<int>& nums) {
        sol(0,nums);
        return ans;
    }
    bool check(int i) {
        for (int c : temp) {
            if (c == i)
                return false;
        }
        return true;
    }
    void sol(int ind, vector<int>& nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
           if (ind == nums.size())
            return;
        for(int i=0;i<nums.size();i++){
            if(check(nums[i])){
            temp.push_back(nums[i]);
            sol(ind+1,nums);
            temp.pop_back();
            }
        }
    }
};
