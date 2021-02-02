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
	bool isPalindrome(ListNode* head) {
		int n = 0, i;
		ListNode *trav = head, *prev, *next, *left, *right, *save;

		while (trav)
		{
			n++;
			trav = trav->next;
		}
		if (n <= 1)
			return true;
		//cout<<n;
		right = head;
		for (i = 0; i < n / 2; i++)
		{
			left = right;
			right = right->next;
		}
		if (n % 2) right = right->next;
		trav = head;
		prev = NULL;
		save = left->next;
		//cout<<' '<<left->val<<' '<<right->val<<'\n';
		while (trav != save)
		{
			next = trav->next;
			trav->next = prev;
			prev = trav;
			trav = next;
		}
		while (left && right)
		{
			if (left->val != right->val)
				return false;
			left = left->next;
			right = right->next;
		}
		return true;
	}
};