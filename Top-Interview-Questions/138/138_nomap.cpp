/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *trav=head, *t2, *ans;
        while(trav)
        {
            t2 = new Node(trav->val);
            t2->next = trav->next;
            trav->next = t2;
            trav = trav->next->next;
        }
        trav = head;
        while(trav)
        {
            trav->next->random = trav->random ? trav->random->next : NULL;
            trav = trav->next->next;
        }
        trav = head;
        ans = trav->next;
        while(trav)
        {
            t2 = trav->next;
            trav->next = t2->next;
            t2->next = t2->next ? t2->next->next : NULL;
            trav = trav->next;
        }
        return ans;
        
    }
};