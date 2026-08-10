class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    void dfs(
        string word,
        string& beginWord,
        unordered_map<string, vector<string>>& parents
    ) {
        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
        } 
        else {
            for (string& parent : parents[word]) {
                dfs(parent, beginWord, parents);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );

        if (!words.count(endWord))
            return {};

        unordered_map<string, int> dist;

        unordered_map<string, vector<string>> parents;

        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currentDist = dist[word];

            for (int i = 0; i < word.size(); i++) {

                string next = word;

                for (char c = 'a'; c <= 'z'; c++) {

                    if (c == word[i])
                        continue;

                    next[i] = c;

                    if (!words.count(next))
                        continue;

                    // First time discovering this word
                    if (!dist.count(next)) {

                        dist[next] = currentDist + 1;

                        parents[next].push_back(word);

                        q.push(next);
                    }

                    // Another shortest path
                    else if (dist[next] == currentDist + 1) {

                        parents[next].push_back(word);
                    }
                }
            }
        }

        if (!dist.count(endWord))
            return {};

        dfs(endWord, beginWord, parents);

        return result;
    }
};