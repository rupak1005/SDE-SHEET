class Solution {
public:
    ListNode* revLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle (slow will be at middle)
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For odd length, skip the middle node
        if (fast) slow = slow->next;

        // Reverse second half
        ListNode* secondnode = revLL(slow);

        // Compare both halves
        ListNode* firstnode = head;
        while (secondnode) {
            if (firstnode->val != secondnode->val) return false;
            firstnode = firstnode->next;
            secondnode = secondnode->next;
        }

        return true;
    }
};
