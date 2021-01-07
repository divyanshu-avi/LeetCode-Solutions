/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void recur(Node* L, Node* R)
    {
        if(!L)
            return;
        L->next = R;
        recur(L->left, L->right);
        recur(L->right, R->left);
        recur(R->left, R->right);
    }
    
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        recur(root->left,root->right);
        return root;
    }
};