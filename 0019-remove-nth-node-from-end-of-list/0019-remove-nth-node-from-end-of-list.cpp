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
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;

        }
         if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int elem=len-n;
        temp=head;
        while(elem-1){
            temp=temp->next;
            elem--;

        }
        ListNode* delNode=temp->next;
        temp->next=temp->next->next;
        delNode->next=NULL;
        delete delNode;

        return head;
    }
    
};