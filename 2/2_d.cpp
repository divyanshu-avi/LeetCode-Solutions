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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(), *temp;
        int carry, sum, len1 = 0, len2 = 0, diff;
        //If one is empty just return the other
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        temp = ans;
        temp->val = (l1->val + l2->val)%10;
        carry = (l1->val + l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2)
        {
            sum = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            temp->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while(l1)
        {
            sum = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            temp->next = new ListNode(sum);
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2)
        {
            sum = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            temp->next = new ListNode(sum);
            l2 = l2->next;
            temp = temp->next;
        }
        if(carry)
            temp->next = new ListNode(carry);
        return ans;
    }
};