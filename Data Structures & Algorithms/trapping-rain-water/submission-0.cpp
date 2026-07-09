class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size());
        vector<int> rmax(height.size());
        int l=-1;
        int r=-1;
        for(int i=0;i<height.size();i++){
            lmax[i]=l;
            l=max(l,height[i]);
        }
        for(int i=height.size()-1;i>=0;i--){
            rmax[i]=r;
            r=max(r,height[i]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=max(min(lmax[i],rmax[i])-height[i],0);
        }
        return ans;
    }
};
