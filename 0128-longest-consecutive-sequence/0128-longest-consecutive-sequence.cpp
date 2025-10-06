class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int lcs=1;
        int ccs=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])continue;
            if(nums[i]==nums[i-1]+1)ccs++;
            else{
                ccs=1;
            }
            lcs=max(lcs,ccs);


        }
        return lcs;
    }
};