class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return abs((a[0]*a[0])+(a[1]*a[1]))>abs((b[0]*b[0])+(b[1]*b[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,decltype(&comp)> pq(points.begin(),points.end(),comp);
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }   
};
