class Solution {
public:
    int jump(vector<int>& nums) {
        int jump=0;
        int l=0;
        int r=0;
        while(r<nums.size()-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(i+nums[i],farthest);
            }
            l=r+1;
            r=farthest;
            jump++;
        }
        return jump;
    }
};