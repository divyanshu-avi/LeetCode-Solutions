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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        if(l1->val > l2->val)
            return mergeTwoLists(l2,l1);
        ListNode *next1, *next2, *ans = l1;
        while(l1 && l2)
        {
            next1 = l1->next;
            next2 = l2->next;
            if(!next1)
            {
                l1->next = l2;
                return ans;
            }
            else if(l2->val<=next1->val)
            {
                l1->next = l2;
                l2->next = next1;
                l2 = next2;
                l1 = l1->next;
            }
            else
                l1 = l1->next;
        }
        return ans;
    }
};