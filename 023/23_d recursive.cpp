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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i, lowidx, low=INT_MAX;
        for(i=0;i<lists.size();i++)
            if(lists[i] && lists[i]->val<low)
            {
                low = lists[i]->val;
                lowidx = i;
            }
        ListNode *ans = nullptr;
        if(low==INT_MAX)
            return ans;
        ans = lists[lowidx];
        lists[lowidx] = lists[lowidx]->next;
        ans->next = mergeKLists(lists);
        return ans;
    }
};