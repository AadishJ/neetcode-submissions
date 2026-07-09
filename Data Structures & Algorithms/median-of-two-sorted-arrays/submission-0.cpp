class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size())
            return findMedianSortedArrays(b, a);

        int total = a.size() + b.size();
        int med = total / 2;

        int l = 0, h = a.size() - 1;
        int m = -1;

        while (l <= h) {
            m = l + (h - l) / 2;

            int Aleft  = (m >= 0) ? a[m] : INT_MIN;
            int Aright = (m + 1 < a.size()) ? a[m + 1] : INT_MAX;

            int j = med - m - 2;

            int Bleft  = (j >= 0) ? b[j] : INT_MIN;
            int Bright = (j + 1 < b.size()) ? b[j + 1] : INT_MAX;

            if (Aleft > Bright) {
                h = m - 1;
            } else if (Bleft > Aright) {
                l = m + 1;
            } else {
                break;
            }
        }

if (l > h)
    m = h;
        int Aleft  = (m >= 0) ? a[m] : INT_MIN;
        int Aright = (m + 1 < a.size()) ? a[m + 1] : INT_MAX;

        int j = med - m - 2;

        int Bleft  = (j >= 0) ? b[j] : INT_MIN;
        int Bright = (j + 1 < b.size()) ? b[j + 1] : INT_MAX;

        if (total % 2)
            return min(Aright, Bright);

        return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
    }
};