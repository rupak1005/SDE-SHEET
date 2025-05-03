class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        int n = nums.size();
        
        // Step 1: Find first index from right where nums[i] < nums[i+1]
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: If no such index, reverse entire array
        if(ind == -1) {
            reverse(nums.begin(), nums.end());
            return;  // important to return here!
        }

        // Step 3: Find element just greater than nums[ind] from right side
        for(int i = n - 1; i > ind; i--) {
            if(nums[i] > nums[ind]) {
                swap(nums[ind], nums[i]);
                break;
            }
        }

        // Step 4: Reverse from ind+1 to end
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
