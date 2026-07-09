#include <bits/stdc++.h>
using namespace std;

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

class TimeMap {
public:
        unordered_map<string,vector<pair<string,int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> temp = mp[key];
        int low=0,high=temp.size()-1,mid=0;
        while(low<=high){
            mid=low + (high-low)/2;
            if(temp[mid].second>timestamp){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(high==-1) return "";
        return temp[high].first;
    }
};
