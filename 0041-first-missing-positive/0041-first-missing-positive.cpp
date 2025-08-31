class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int missing=1;
        for(auto i:nums){
            if(missing==i)missing++;
        }
        return missing;
    }
};