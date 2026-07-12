class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int p;
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            pq.push(i);
        }
        while(pq.size()>k){
            pq.pop();
        }
        p=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>p) pq.pop();
        return pq.top();
    }
};
