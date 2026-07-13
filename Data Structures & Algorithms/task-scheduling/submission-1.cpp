class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26];
        for (char c : tasks) {
            arr[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) pq.push(arr[i]);
        }
        int ans = 0;
        int s = 0;
        while (!pq.empty()) {
            ans++;
            vector<int> temp;
            s = 0;
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    if (pq.top() > 1) temp.push_back(pq.top() - 1);
                    pq.pop();
                } else {
                    s++;
                }
            }
            while (!temp.empty()) {
                pq.push(temp.back());
                temp.pop_back();
            }
        }
        return ans * (n+1) - s;
    }
};
