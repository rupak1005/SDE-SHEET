class Solution {
public:

    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {

        // Same string
        if (s1 == s2) {
            return true;
        }

        // Different lengths
        if (s1.size() != s2.size()) {
            return false;
        }

        int n = s1.size();

        // Character frequency check
        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        for (int x : count) {
            if (x != 0) {
                return false;
            }
        }

        // Create memoization key
        string key = s1 + "#" + s2;

        if (memo.count(key)) {
            return memo[key];
        }

        // Try every split
        for (int split = 1; split < n; split++) {

            // Case 1: No swap
            bool noSwap =
                solve(
                    s1.substr(0, split),
                    s2.substr(0, split)
                )
                &&
                solve(
                    s1.substr(split),
                    s2.substr(split)
                );

            if (noSwap) {
                return memo[key] = true;
            }

            // Case 2: Swap
            bool swap =
                solve(
                    s1.substr(0, split),
                    s2.substr(n - split)
                )
                &&
                solve(
                    s1.substr(split),
                    s2.substr(0, n - split)
                );

            if (swap) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {

        return solve(s1, s2);
    }
};