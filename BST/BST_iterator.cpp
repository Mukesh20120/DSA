//1.method  naive approach make a vector and store the value in sorted order or inorder
// TC for function o(1) but sc O(n) due to vector

class BSTIterator {
    private:
    int i;
    vector<int>val;
public:
    BSTIterator(TreeNode* root) {
        i=0;
        Inorder(root);
    }
    void Inorder(TreeNode *node){
        if(node){
            Inorder(node->left);
            val.push_back(node->val);
            Inorder(node->right);
        }
    }
    int next() {
        return val[i++];
    }
    
    bool hasNext() {
        return i<val.size();
    }
};

/*
2 method optimal solution 
we make a stack to do inorder traversal by iterating BST
ex we take all the left left left in stack
and if ask for next pop out the node and 
store all the node move right and store left left left 

remember inorder traversal through iterator using stack TC o(1) SC o(H)
*/


class BSTIterator {
    stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
        //we push all the left
        pushall(root);
    }
    
    int next() {
        TreeNode *node=st.top();
        st.pop();
        pushall(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    void pushall(TreeNode *node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
};
