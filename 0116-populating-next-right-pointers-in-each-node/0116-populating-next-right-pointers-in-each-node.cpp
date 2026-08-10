class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            Node* prev = nullptr;

            while (size--) {
                Node* curr = q.front();
                q.pop();

                if (prev != nullptr)
                    prev->next = curr;

                prev = curr;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            // Last node of each level
            prev->next = nullptr;
        }

        return root;
    }
};