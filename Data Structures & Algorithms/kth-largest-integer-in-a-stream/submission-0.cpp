class KthLargest {
public:
    multiset<int,greater<int>> s;
    int p;
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            s.insert(i);
        }
        p=k;
    }
    
    int add(int val) {
        s.insert(val);
        int a=0;
        for(int i: s){
            cout << i << ' ';
            a++;
            if(a==p)
                return i;
        }
        cout << endl;
        return -1;
    }
};
