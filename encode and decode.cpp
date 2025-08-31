#include <iostream>
#include <vector>
#include <string>
using namespace std;

string encode(const vector<string>& strs) {
    string ans;
    for (const auto& s : strs) {
        ans += to_string(s.size()) + "#" + s;
    }
    return ans;
}

vector<string> decode(const string& s) {
    vector<string> ans;
    int i = 0;
    while (i < s.size()) {
        int j = i;
        // Find the position of the delimiter '#'
        while (j < s.size() && s[j] != '#') j++;
        if (j == s.size()) break; // Malformed input, no delimiter found
        int len = stoi(s.substr(i, j - i));
        ans.push_back(s.substr(j + 1, len));
        i = j + 1 + len;
    }
    return ans;
}

int main() {
    vector<string> strs = {"neet", "code", "love", "you"};
    string encoded = encode(strs);
    vector<string> ans = decode(encoded);
    for (const auto& s : ans) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}