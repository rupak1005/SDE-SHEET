class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;

        while (current != nullptr &&
               current->next != nullptr) {

            if (current->val ==
                current->next->val) {

                // Remove duplicate node
                current->next =
                    current->next->next;

            } else {

                // Move forward
                current = current->next;
            }
        }

        return head;
    }
};