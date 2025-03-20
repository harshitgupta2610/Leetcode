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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        vector<int> values;
        ListNode* curr = head;
        while (curr) {
            values.push_back(curr->val);
            curr = curr->next;
        }
        for (int i = 0; i < values.size(); i += k) {
            if (i + k <= values.size()) {
                reverse(values.begin() + i, values.begin() + i + k);
            }
        }
        ListNode* dummy = new ListNode(0); 
        ListNode* tail = dummy;
        for (int val : values) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next; 
    }
};