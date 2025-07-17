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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 =NULL;
        ListNode* p2 =NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            if(p2!=NULL){
                p2=p2->next;
            }
            k--;
            if(k==0){
                p2=head;
                p1=temp;
            }
            temp = temp->next;
        }
        swap(p1->val,p2->val);
        return head;
    }
};