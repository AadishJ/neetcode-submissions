class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        for(int i=0;i<k;i++) ms.insert(nums[i]);
        vector<int> ans;
        ans.push_back(*ms.rbegin());
        for(int i=1;i<=nums.size()-k;i++){
            auto it = ms.find(nums[i-1]);
            ms.erase(it);
            ms.insert(nums[i+k-1]);
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};
