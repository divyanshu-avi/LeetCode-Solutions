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
//This code is HEAVILY inspired from someone's code I read in the discussions.
//It was just so elegant.
class Solution {
public:
	ListNode* divide(ListNode* head, int n)
	{
		if (!head) return NULL;
		int i;
		for (i = 0; i < n - 1 && head->next ; i++)
			head = head->next;
		ListNode* ans = head->next;
		head->next = NULL;
		return ans;
	}

	ListNode* merge(ListNode* l1, ListNode* l2, ListNode* end)
	{
		ListNode* t = end;
		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				t->next = l1;
				l1 = l1->next;
			}
			else
			{
				t->next = l2;
				l2 = l2->next;
			}
			t = t->next;
		}
		while (l1)
		{
			t->next = l1;
			l1 = l1->next;
			t = t->next;
		}
		while (l2)
		{
			t->next = l2;
			l2 = l2->next;
			t = t->next;
		}
		return t;
	}

	ListNode* sortList(ListNode* head) {
		int n = 0;
		ListNode* t = head;
		while (t)
		{
			n++;
			t = t->next;
		}
		if (!n)
			return NULL;
		//Now we have the lenth of the linked list
		ListNode *l, *r, *ans = new ListNode(), *beg, *end;
		ans->next = head;
		//We will merge 2 linked lists of length i to make a single list of length 2*i
		//And keep doubling i at every step. Of course we need to take care of the bounds of the list.
		for (int i = 1; i < n; i *= 2)
		{
			beg = ans->next;//beg means begining of current list
			end = ans;//end means end of previous list
			while (beg)
			{
				l = beg;
				r = divide(l, i);
				beg = divide(r, i);
				end = merge(l, r, end);
				//merge will append the new list to end. Then end will be updated to the end of the new list.
			}
		}
		return ans->next;

	}
};