class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;

        while (i < version1.size() || j < version2.size()) {
            long long num1 = 0;
            long long num2 = 0;

            // Read one revision from version1
            while (i < version1.size() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Read one revision from version2
            while (j < version2.size() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2)
                return -1;

            if (num1 > num2)
                return 1;

            // Skip '.'
            if (i < version1.size())
                i++;

            if (j < version2.size())
                j++;
        }

        return 0;
    }
};