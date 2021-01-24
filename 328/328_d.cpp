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
	ListNode* oddEvenList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode *odd = head, *even = head->next, *trav, *save = head->next;
		while (even && even->next)
		{
			trav = even->next;
			odd->next = trav;
			even->next = trav != nullptr ? trav->next : nullptr;
			odd = odd->next;
			even = even->next;
		}
		odd->next = save;
		return head;
	}
};