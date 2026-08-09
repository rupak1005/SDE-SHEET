class Solution {
public:

    vector<string> result;
    vector<string> parts;

    void backtrack(
        string& s,
        int index
    ) {

        // We have 4 parts
        if (parts.size() == 4) {

            if (index == s.size()) {

                string ip;

                for (int i = 0;
                     i < parts.size();
                     i++) {

                    if (i > 0)
                        ip += ".";

                    ip += parts[i];
                }

                result.push_back(ip);
            }

            return;
        }

        // Try 1, 2, or 3 digits
        for (int len = 1;
             len <= 3;
             len++) {

            if (index + len > s.size())
                break;

            // Leading zero
            if (len > 1 &&
                s[index] == '0') {
                break;
            }

            string part =
                s.substr(index, len);

            int value = stoi(part);

            // Must be <= 255
            if (value > 255)
                break;

            // Choose
            parts.push_back(part);

            // Explore
            backtrack(
                s,
                index + len
            );

            // Undo
            parts.pop_back();
        }
    }

    vector<string> restoreIpAddresses(
        string s
    ) {

        backtrack(s, 0);

        return result;
    }
};