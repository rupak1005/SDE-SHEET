class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if (head == nullptr)
            return nullptr;

        ListNode dummy(0);

        ListNode* curr = head;

        while (curr != nullptr) {

            // Save next node
            ListNode* next = curr->next;

            // Find insertion position
            ListNode* prev = &dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {

                prev = prev->next;
            }

            // Insert curr
            curr->next = prev->next;
            prev->next = curr;

            // Move to next original node
            curr = next;
        }

        return dummy.next;
    }
};