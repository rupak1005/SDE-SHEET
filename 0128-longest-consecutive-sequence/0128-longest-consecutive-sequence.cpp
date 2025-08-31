class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;  // Handle empty input

        sort(nums.begin(), nums.end());
        int ccs = 1;  // current consecutive sequence length
        int lcs = 1;  // longest consecutive sequence length
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) continue;  // skip duplicates
            if(nums[i] == nums[i-1] + 1) {
                ccs++;
            } else {
                ccs = 1;
            }
            lcs = max(lcs, ccs);
        }
        return lcs;
    }
};
