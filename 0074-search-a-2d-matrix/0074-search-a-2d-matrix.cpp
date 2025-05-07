class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=(n*m)-1; //pura size
        while(s<=e){
            int mid=s+(e-s)/2;
            int row=mid/m,col=mid%m;//to find row and col
            if(matrix[row][col]==target)return true;
            if(matrix[row][col]<target)s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};