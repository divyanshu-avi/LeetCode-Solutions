/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode *slow = head, *fast = head->next;
        
        while(fast!=slow && fast)
        {
            slow = slow->next;
            //fast->next can become NULL so can't use fast->next->next blindly.
            fast = fast->next ? fast->next->next : NULL;
        }
        return fast!=NULL;
        
    }
};