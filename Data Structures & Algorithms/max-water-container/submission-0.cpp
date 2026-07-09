class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int maxi=0;
        while(l<r){
            int w = r-l;
            int h = min(heights[r],heights[l]);
            int area = w*h;
            maxi=max(maxi,area);
            if(heights[r]>heights[l]){
                l++;
            }else{
                r--;
            }
        }   
        return maxi;
    }
};