class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> ind;
        vector<int> ans(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            if(ind.empty()) ind.push(i);
            else if(temperatures[ind.top()]>=temperatures[i]) ind.push(i);
            else{
                while(!ind.empty() && temperatures[ind.top()]<temperatures[i]){
                    ans[ind.top()]=i-ind.top();
                    ind.pop();
                }
                ind.push(i);
            }
        }
        return ans;
    }
};
