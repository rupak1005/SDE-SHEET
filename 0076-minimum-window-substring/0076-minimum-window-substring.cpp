class Solution {
public:
    string minWindow(string s, string t) {
          if (t.size() > s.size()) return "";

        unordered_map<char, int> target, window;
        for (char c : t) target[c]++;

        int have = 0, need = target.size();
        int left = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (target.count(c) && window[c] == target[c])
                have++;

            // Try shrinking from left
            while (have == need) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                window[s[left]]--;
                if (target.count(s[left]) && window[s[left]] < target[s[left]])
                    have--;
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};