/*
easy question  divide and conqure
optimal solution
steps Base case
    head null then return null
    head next null then there is one value return one treeNode 
    2.find the middle element of the linked list
      slow and fast a tail pointer to follow slow
      make a treenode of slow value 
      make previous next null so that we can divide the list into two part
    3 pass the half which is low than root->val on left side and other half on right side
    4 return root

*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);
        ListNode *slow=head,*fast=head,*prev=head;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        TreeNode *root=new TreeNode(slow->val);
        prev->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
    }
};

