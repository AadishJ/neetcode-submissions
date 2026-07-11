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
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
            nums[abs(nums[i])-1]*=-1;
            cout << nums << endl;
        }
        return -1;
    }
};
