class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high=*max_element(piles.begin(),piles.end()),mid=0;
        while(low<=high){
            mid = low + (high-low)/2;
            if(test(piles,mid)<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
    int test(vector<int>& piles, int s){
        int ans=0;
        for(int i: piles){
            ans+=((i+s-1)/s);
        }
        cout << s << ' ' << ans << endl;
        return ans;
    }
};
