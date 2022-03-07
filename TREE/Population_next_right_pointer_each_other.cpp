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
    Node* connect(Node* root) {
        //base case
        if(!root)return root;

        //simple level order traversal
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            Node *prev=NULL; //to store the previous node
            for(int i=0;i<n;i++){
                Node *temp=q.front();
                q.pop();
                if(i==0)prev=temp; //when we encounter with first node
                else{
                    prev->next=temp; //doing our work 
                    prev=temp;  //moving the previous pointer to next 
                }
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        return root;
    }
};