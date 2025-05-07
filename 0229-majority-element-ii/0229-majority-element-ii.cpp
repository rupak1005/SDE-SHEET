class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;
        
        sort(nums.begin(), nums.end());
        
        int cnt = 1;  // start from 1 since nums[0] already counted
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1]) {
                cnt++;
            } else {
                if (cnt > n / 3) {
                    ans.push_back(nums[i-1]);
                }
                cnt = 1; // reset for new number
            }
        }
        
        // check last element
        if (cnt > n / 3) {
            ans.push_back(nums[n-1]);
        }
        
        return ans;
    }
};
