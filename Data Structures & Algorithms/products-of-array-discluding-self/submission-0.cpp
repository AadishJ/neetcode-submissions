template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 != v.size())
            os << ", ";
    }
    os << "]";
    return os;
}
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()+2),pos(nums.size()+2);
        pre.back()=1;
        pre[0]=1;
        pos.back()=1;
        pos[0]=1;
        int s=1,p=1;;
        for(int i=1;i<=nums.size();i++){
            s*=nums[i-1];
            pre[i]=s;
            p*=nums[nums.size()-i];
            pos[nums.size()-i+1]=p;
        }
        vector<int> ans(nums.size());
        for(int i=1;i<=nums.size();i++){
            ans[i-1]=pos[i+1]*pre[i-1];
        }
       return ans;
    }
};
