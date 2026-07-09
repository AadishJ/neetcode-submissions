class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1,mid=0;
        while(low<=high){
            mid = low+(high-low)/2;
            if(matrix[mid][0]>target){
                high=mid-1;
            }else if(matrix[mid][0]<target){
                low=mid+1;
            }else{
                return true;
            }
        }
        int row = high;
        if(row<0) return false;
        low=0;high=matrix[0].size()-1;
        while(low<=high){
            mid = low + (high-low)/2;
            if(matrix[row][mid]>target){
                high=mid-1;
            }else if(matrix[row][mid]<target){
                low=mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};
