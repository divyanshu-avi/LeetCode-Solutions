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
    ListNode* reverseList(ListNode* head) {
        
        ListNode *prev,*curr,*next;
        
        if(head == NULL)
            return NULL;
        
        prev = NULL;
        curr = head;
        next = head->next;
        
        while(next){
            
            curr ->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
            
        }
        curr->next = prev;
        return curr;
        
        
    }
};