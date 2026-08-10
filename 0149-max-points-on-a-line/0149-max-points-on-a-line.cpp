class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if (n <= 2)
            return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {

            unordered_map<string, int> mp;

            int duplicate = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                // Duplicate point
                if (dx == 0 && dy == 0) {
                    duplicate++;
                    continue;
                }

                // Normalize slope
                int g = gcd(abs(dx), abs(dy));

                dx /= g;
                dy /= g;

                // Keep sign consistent
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                // Vertical line
                if (dx == 0) {
                    dy = 1;
                }

                // Horizontal line
                if (dy == 0) {
                    dx = 1;
                }

                string slope = to_string(dy) + "/" + to_string(dx);

                mp[slope]++;

                localMax = max(localMax, mp[slope]);
            }

            ans = max(ans, localMax + duplicate + 1);
        }

        return ans;
    }
};