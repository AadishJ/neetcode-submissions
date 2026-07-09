
// ---------- pair ----------
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

// ---------- tuple ----------
template<typename Tuple, size_t... Is>
void printTuple(ostream& os, const Tuple& t, index_sequence<Is...>) {
    ((os << (Is ? ", " : "") << get<Is>(t)), ...);
}

template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << "(";
    printTuple(os, t, index_sequence_for<Args...>{});
    return os << ")";
}

// ---------- iterable containers ----------
template<typename T, typename = decltype(begin(declval<T>())),
         typename = enable_if_t<!is_same_v<T, string>>>
ostream& operator<<(ostream& os, const T& container) {
    os << "[";
    bool first = true;
    for (const auto& x : container) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    return os << "]";
}
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        return a.first>b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;
        for(int i=0;i<position.size();i++){
            p.push_back({position[i],speed[i]});
        }
        sort(p.begin(),p.end(),comp);
        stack<double> st;
        double curTime=0;
        int ans=0;
        for(int i=0;i<p.size();i++){
            double time = (double)(target-p[i].first)/p[i].second;
            if(time>curTime){
                curTime=time;
                ans++;
            }
        }
        return ans;
    }
};
