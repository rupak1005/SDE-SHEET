class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;
            int x = p.second.first;  // vertical
            int y = p.second.second; // level

            nodes[x][y].insert(temp->val);

            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Move this outside the while loop
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
