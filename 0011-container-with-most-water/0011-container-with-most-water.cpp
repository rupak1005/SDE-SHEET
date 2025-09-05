class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size()-1;
        int l=0;
        int r=n;
        int maxarea=0;
        while(l<r){
            int area=(r-l)*min(height[l],height[r]);
            maxarea=max(area,maxarea);
            if(height[l]<height[r])l++;
            else if(height[r]<height[l])r--;
            else{
                l++;
                r--;
            }


        }
        return maxarea;
    }
};