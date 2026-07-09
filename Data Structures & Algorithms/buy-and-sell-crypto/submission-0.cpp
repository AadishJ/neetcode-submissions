class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int bp=prices[0];
        int mp=0;
        for(int i=1;i<prices.size();i++){
            if(bp>prices[i]){
                bp=prices[i];
            }else{
                mp=max(prices[i]-bp,mp);
            }
        }
        return mp;
    }
};
