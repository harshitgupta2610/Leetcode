/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        ListNode point  =  head;
        int num = 0;
        int len = 0;
        while( point !=null){
            len++;
            point = point.next;
        }
        point = head;
        while( point !=null){
            len--;
            if(point.val == 1){
                num += (1 << len);
            }
            point = point.next;
        }
        return num;
    }
}