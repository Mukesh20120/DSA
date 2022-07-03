//preorder using morris traversal 

vector <int> preorder(Node* root)
{
  // Your code here
        vector<int>pre;
        //make a node to trvaverse though the tree
        Node *cur=root;
        //run loop until cur is not null
        while(cur!=NULL){
            //we have two cases 
            //1 we are at the end of the left side of tree
            if(cur->left==NULL){
                pre.push_back(cur->data);
                cur=cur->right;
            }
            //now we it have left and right we mark the prev
            else{
                Node *prev=cur->left;
                //we go to extreme right
                //two cases 
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    pre.push_back(cur->data);
                    cur=cur->left;
                }
                else{
                    //prev->right ==cur then we have to remove
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return pre;
}