class Solution {
public:
    vector<int> twoSum(vector<int>& n, int target) {
        int curSum=n[0]+n.back();
        int st=0,en=n.size()-1;
        while(curSum!=target){
            if(curSum>target){
                curSum-=n[en--];
                curSum+=n[en];
            }else{
                curSum-=n[st++];
                curSum+=n[st];
            }
        }
        return {st+1,en+1};
    }
};
