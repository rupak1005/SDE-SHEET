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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(-1);
        ListNode* back=dummy;
        ListNode* front=dummy;
        dummy->next=head;

        for(int i=0;i<=n;i++){
            front=front->next;
        }
        while(front){
            front=front->next;
            back=back->next;
        }
        ListNode* delNode=back->next;
        back->next=back->next->next;
        delete delNode;

        ListNode* newhead=dummy->next;
        delete dummy;
        return newhead;
    }
};