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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int n=1,m=1;
        
        ListNode* temp;
        temp = headA;
        while(temp){
            temp = temp->next;
            n++;
        }
        
        temp = headB;
        
        while(temp){
            temp = temp->next;
            m++;
        }
        
        if(n<m)
            return getIntersectionNode(headB,headA);
        
        int dif = n-m;
        while(dif--)
            headA= headA->next;
        
        ListNode* ans = NULL;
        
        while(m--){
            
            if(headA==headB){
                return headA;
            }
            
            headA = headA->next;
            headB = headB->next;
            
        }
        
        return ans;
        
    }
};