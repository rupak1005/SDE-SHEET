class Solution {
public:
     bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> map1(26, 0), map2(26, 0);

        // Count frequency for s1 and first window of s2
        for (int i = 0; i < n1; i++) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        // Check the first window
        if (map1 == map2) return true;

        // Slide the window
        for (int i = n1; i < n2; i++) {
            map2[s2[i] - 'a']++;          // Add new char
            map2[s2[i - n1] - 'a']--;     // Remove char going out

            if (map1 == map2)
                return true;
        }

        return false;
    
    }
};