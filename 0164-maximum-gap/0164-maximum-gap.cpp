class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx)
            return 0;

        int bucketSize = max(1, (mx - mn + n - 2) / (n - 1));

        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        vector<bool> used(bucketCount, false);

        // Put numbers into buckets
        for (int num : nums) {
            int idx = (num - mn) / bucketSize;

            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        int ans = 0;
        int prevMax = mn;

        for (int i = 0; i < bucketCount; i++) {

            if (!used[i])
                continue;

            ans = max(ans, bucketMin[i] - prevMax);

            prevMax = bucketMax[i];
        }

        return ans;
    }
};