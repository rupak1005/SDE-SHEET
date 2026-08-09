class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(
        vector<int>& nums,
        vector<bool>& used
    ) {

        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Skip duplicate branches
            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1]) {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used);

            // Undo
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(
        vector<int>& nums
    ) {

        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);

        backtrack(nums, used);

        return result;
    }
};