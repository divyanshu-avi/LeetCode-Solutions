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
        
        Node* curr = head;
        Node* ans;
        
        while(curr){
            
            Node* n = new Node(curr->val);
            n->next = curr->next;
            curr->next = n;
            curr = n->next;
            
        }
        
        curr = head;
        
        while(curr){
            
            if(curr->random)
            curr->next->random = curr->random->next;
            curr = curr->next->next;
            
        }
        
        curr = head;
        Node* temp;
        
        ans = head->next;
        
        while(curr){
            temp = curr->next;
            curr->next = temp->next;
            
            if(temp->next)
            temp->next = curr->next->next;
            
            curr = curr->next;
            
        }
        
        return ans;
    }
};