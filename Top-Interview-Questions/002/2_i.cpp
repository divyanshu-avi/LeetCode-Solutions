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
        ListNode* sum=new ListNode();
        ListNode* start=sum;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            sum->next=new ListNode();
            sum=sum->next;
            if(l1!=NULL && l2!=NULL){
                int temp=l1->val+l2->val+carry;
                sum->val=temp%10;
                carry=temp/10;
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1==NULL && l2!=NULL){
                int temp=l2->val+carry;
                sum->val=temp%10;
                carry=temp/10;
                l2=l2->next;
            }
            else if(l1!=NULL && l2==NULL){
                int temp=l1->val+carry;
                sum->val=temp%10;
                carry=temp/10;
                l1=l1->next;
            }
            
            //sum=sum->next;
        }
        //sum->next=NULL;
        if(carry==1){
            sum->next=new ListNode(1);
        }
        return start->next;
    }
};
