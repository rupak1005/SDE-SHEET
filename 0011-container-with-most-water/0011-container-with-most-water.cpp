class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int maxArea=0;
        int width=0;
        while(left<right){
            width=right-left;
            maxArea=max(maxArea,width*min(height[left],height[right]));

            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};