class Solution {
public:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode * ans = new ListNode(0);
    
    if(!l1){
        return l2;
    }else if(!l2){
        return l1;
    }
    if(l1->val <= l2->val){
        ans = l1;
        ans->next = mergeTwoLists(l1->next,l2);
    }else{
        ans = l2;
        ans->next = mergeTwoLists(l1,l2->next);
    }
    return ans;
}
};
