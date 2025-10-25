/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
 struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap based on node value
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // Step 1: Push first node of each list
        for (auto list : lists) {
            if (list) pq.push(list);
        }

        // Dummy head for merged list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        // Step 2: Merge process
        while (!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            tail->next = node;
            tail = tail->next;
            
            if (node->next)
                pq.push(node->next);
        }
        
        return dummy->next;
    }
};