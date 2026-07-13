class MedianFinder {
   public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() {}

    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
        } else {
            if (maxHeap.top() < num)
                minHeap.push(num);
            else
                maxHeap.push(num);
        }
        while (((int)minHeap.size() - (int)maxHeap.size()) > 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while ((int)maxHeap.size() - (int)minHeap.size() > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        // cout << minHeap.size() << ' ' << maxHeap.size() << endl;
        if ((minHeap.size() + maxHeap.size()) % 2 == 0) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return maxHeap.top();
        }
    }
};
