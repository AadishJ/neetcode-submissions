class Twitter {
   public:
    struct comp {
        bool operator()(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
    };
    int t;
    unordered_map<int, unordered_set<int>> f;
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, comp>> posts;
    Twitter() { t = 0; }

    void postTweet(int userId, int tweetId) { posts[userId].push({tweetId, t++}); }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> anspq;
        for (int i : f[userId]) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq = posts[i];
            int p = 0;
            while (p != 10 && !pq.empty()) {
                anspq.push(pq.top());
                pq.pop();
                p++;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq = posts[userId];
        int p = 0;
        while (p != 10 && !pq.empty()) {
            anspq.push(pq.top());
            pq.pop();
            p++;
        }
        int l = 0;
        while (!anspq.empty() && l != 10) {
            ans.push_back(anspq.top().first);
            anspq.pop();
            l++;
        }
        return ans;
    }

void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
        f[followerId].insert(followeeId);
}
    void unfollow(int followerId, int followeeId) { f[followerId].erase(followeeId); }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */