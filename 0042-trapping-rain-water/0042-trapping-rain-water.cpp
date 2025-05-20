class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxleft=0,maxright=0;
        int res=0;

        while(l<=r){
            if(height[l]<=height[r]){
                if(maxleft<=height[l])maxleft=height[l];
                else{
                    res+=maxleft-height[l];
                }
                l++;
            }else{
                if(maxright<=height[r])maxright=height[r];
                else{
                    res+=maxright-height[r];
                }
                r--;
            }
        }
        
        return res;
    }
};