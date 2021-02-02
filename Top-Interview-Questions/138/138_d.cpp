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
        Node *ans = NULL, *trav=head, *trav2;
        unordered_map<Node*, Node*> map;
        while(trav)
        {
            if(!ans)
            {
                ans = new Node(trav->val);
                trav2 = ans;
            }
            else
            {
                trav2->next = new Node(trav->val);
                trav2 = trav2->next;
            }
            map.insert({trav, trav2});
            trav = trav->next;
        }
        trav = head; trav2 = ans;
        while(trav)
        {
            trav2->random = map[trav->random];
            trav = trav->next;
            trav2 = trav2->next;
        }
        return ans;
        
    }
};