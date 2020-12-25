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
        if(!head)
            return nullptr;
        int i;
        ListNode *end = head, *pos, *next;
        for(i=0;i<n && end;i++)
            end = end->next;
        if(i<n-1)
            return head;
        if(!end)
        {
            pos = head->next;
            //free(head);
            return pos;
        }
        pos = head;
        while(end->next)
        {
            end = end->next;
            pos = pos->next;
        }
        next = pos->next;
        pos->next = next->next;
        //free(next);
        return head;            
    }
};