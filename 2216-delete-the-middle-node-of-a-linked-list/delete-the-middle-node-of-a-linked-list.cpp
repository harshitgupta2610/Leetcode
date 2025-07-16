class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr; 
        }
        int n = 0;
        ListNode* current = head;
        while (current) {
            n++;
            current = current->next;
        }
        int middlePos = n / 2;
        ListNode* prev = nullptr;
        current = head;
        for (int i = 0; i < middlePos; i++) {
            prev = current;
            current = current->next;
        }
        if (prev) {
            prev->next = current->next;
        } else {
            head = head->next; 
        }
        return head;
    }
};