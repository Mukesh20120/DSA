//preorder traversal

//recursive approach

void recursivepre(struct Node* root){
    if(root==NULL)
    return;
    //preorder root,left,right
    arr[i++]=root->data;
    recursivepre(root->left);
    recursivepre(root->right);
}
//using stack to traverse just remember the property of stack if you want left at top then you have to insert it in the end of the stack

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode *temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        return ans;
    }
};



//inorder traversal


//recursive left/root/right

void recursivein(struct Node* root){
    if(root==NULL)
    return;
    recursivein(root->left);
    arr[i++]=root->data;
    recursivein(root->right);
}

//using stack and iteration
/*
we run loop two case  we go to the extreme left and then if we find null
we take the value and make node to right and again go to the  extrme left
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode *node=root;
        while(true){
            //here we go until to the left
            if(node!=NULL){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty())break;
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};


//postorder traversal using recursion left /right/root

void recurpost(struct Node *root){
    if(root==NULL)
    return;
    recurpost(root->left);
    recurpost(root->right);
    arr[i++]=root->data;
}

//using 2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        stack<TreeNode*>stk1,stk2;
        stk1.push(root);
        while(!stk1.empty()){
            TreeNode *node=stk1.top();
            stk1.pop();
            stk2.push(node);
            if(node->left)stk1.push(node->left);
            if(node->right)stk1.push(node->right);
        }
        while(!stk2.empty()){
            ans.push_back(stk2.top()->val);
            stk2.pop();
        }
        return ans;
    }
};
