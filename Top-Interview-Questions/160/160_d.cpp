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
    ListNode *getIntersectionNode(ListNode *A, ListNode *B) {
        int n1=0, n2=0, n;
        ListNode *l1 = A, *l2 = B;
        while(l1)
        {
            l1 = l1->next;
            n1++;
        }
        while(l2)
        {
            l2 = l2->next;
            n2++;
        }
        n = abs(n1-n2);
        l1 = A; l2 = B;
        if(n1<n2)
            swap(l1, l2);
        //now l1 is pointing to the longer list and l2 to the shorter
        while(n--)
            l1 = l1->next;
        while(l1 != l2)//If both are null then also l1==l2 will be true
        {
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
};