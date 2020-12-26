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
        int i;
        ListNode *ans = nullptr, *trav;
        pair<int, int> temp;
        priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> >pq;
        for(i=0;i<lists.size();i++)
            if(lists[i])
            {
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            if(lists[temp.second])
            {
                pq.push({lists[temp.second]->val, temp.second});
                lists[temp.second] = lists[temp.second]->next;
            }
            if(!ans)
            {
                ans = new ListNode(temp.first);
                trav = ans;
            }
            else
            {
                trav->next = new ListNode(temp.first);
                trav = trav->next;
            }
        }
        return ans;
    }
};