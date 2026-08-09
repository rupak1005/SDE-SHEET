class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n + 1, 0);

        // Empty string has one valid decoding
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {

            // 0 cannot be decoded alone
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            // Decode one digit
            dp[i] = dp[i + 1];

            // Decode two digits
            if (i + 1 < n) {

                int number =
                    (s[i] - '0') * 10 +
                    (s[i + 1] - '0');

                if (number >= 10 &&
                    number <= 26) {

                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};