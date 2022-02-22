/*
brute force 
step 1 traverse throught the BST and store value in inorder it became
  sorted and 
step 2 question boil down to the two sum problem
  use two pointer to find the sum 
  
  TC o(n) SC o(n)
*/

class Solution {
public:
    void Inorder(TreeNode *node,vector<int>&var){
        if(node){
            Inorder(node->left,var);
            var.push_back(node->val);
            Inorder(node->right,var);
        }
    }
    bool findTarget(TreeNode* root, int k) {
     
        vector<int>var;
        Inorder(root,var);
        
        //we have store the all value in sorted order now question
        //boiled down to 2 sum
        int i,j;
        i=0;
        j=var.size()-1;
        while(i<j){
           int sum=var[i]+var[j];
            if(sum==k)return true;
            if(sum>k)
                j--;
            else
                i++;
        }
        return false;
    }
};

/*
2nd method based on bstiterator we store only height SC boil down to o(H)
same make two stack fill iterate inorder one ascending and other one in decending order
*/

class BSTiterator{
  private:
    stack<TreeNode*>st;
    bool reverse;
    public: 
    //constructor
    BSTiterator(TreeNode* root,bool rev){
        reverse=rev;
        pushall(root,reverse);
    }
    int next(){
        TreeNode *p=st.top();
        st.pop();
        if(reverse)
            pushall(p->left,reverse);
        else
            pushall(p->right,reverse);
    return p->val;
    }
    void pushall(TreeNode*root,bool rev){
        while(root){
            st.push(root);
            if(rev)
            root=root->right;
           else
            root=root->left; 
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k)return true;
            if(i+j>k)
                j=r.next();
            else
                i=l.next();
        }
        return false;
    }
};
