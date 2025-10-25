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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         vector<int> vals;
    for(auto l : lists){
        while(l){ vals.push_back(l->val); l = l->next; }
    }
    sort(vals.begin(), vals.end());
    ListNode dummy(0), *curr = &dummy;
    for(int v : vals){
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy.next;
    }
};