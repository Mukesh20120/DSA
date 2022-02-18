/*
code is not correct for the construction of BST from preorder
need to correct
*/


#include<iostream>

using namespace std;

class TreeNode{
public:
	int data;
	struct TreeNode* left;
	struct TreeNode* right;

	TreeNode(){
		data=0;
		left=right=NULL;
	}
	TreeNode(int x){
		data=x;
		left=right=NULL;
	}
}*root=NULL;

void Insert(int x){
	//first node
	TreeNode *temp=new TreeNode(x);
	if(root==NULL)
		root=temp;
	else{
	TreeNode *tail=root,*node=root;
	while(node){
		tail=node;
		if(node->data>x)
		  node=node->left;
		else
		 node=node->right;
	}
	if(tail->data > x)
	   tail->left=temp;
	else
	   tail->right=temp;
	}
}

void Inorder(TreeNode *node){
	if(node){
		Inorder(node->left);
		cout<<node->data<<" ";
		Inorder(node->right);
	}
}

TreeNode *Search(int x){
	if(root==NULL)return NULL;
	TreeNode *node=root;
	while(node){
		if(node->data==x)
		  return node;
		else if(node->data>x)
		   node=node->left;
		else
		  node=node->right;
	}
}

TreeNode *RSearch(TreeNode *node,int x){
	if(node==NULL)
	   return NULL;
	else if(node->data==x)
	  return node;
	else if(node->data > x)
	  return RSearch(node->left,x);
	else
	  return RSearch(node->right,x);
}

void RInsert(TreeNode *node,TreeNode *tail,int x){
	if(node==NULL){
		TreeNode *temp=new TreeNode(x);
	  if(tail==NULL)
	     root=temp;
	  else if(tail->data > x)
		   tail->left=temp;
    	else
		  tail->right=temp;
	  return;
	}
	else if(node->data > x)
	   RInsert(node->left,node,x);
	else
	   RInsert(node->right,node,x);
}

int height(TreeNode *p){
	if(p==NULL)
	  return 0;
	int x=height(p->left);
	int y=height(p->right);
	
	return x>y?x+1:y+1;
}

TreeNode *InPre(TreeNode *node){
	while(node && node->right){
		node=node->right;
	}
	return node;
}

TreeNode *preSuc(TreeNode *node){
	while(node && node->left){
		node=node->left;
	}
	return node;
}

TreeNode *Delete(TreeNode* p,int key){
	//base case check only root are not there
	//check for the leaf node
	if(p==NULL)return NULL;
	if(!p->left && !p->right){
		if(p==root)
		  root=NULL;
	  delete(p);
	  return NULL;
	}
	
	//traversal find the node which have to delete
	if(p->data > key)
	  p->left=Delete(p->left,key);
	else if(p->data < key)
	  p->right=Delete(p->right,key);
	else{
		//now the key is found we have two option either we take 
		// presucc or we take inse
		TreeNode *q;
		if(height(p->left) > height(p->right)){
			q=InPre(p->left);
			p->data=q->data;
			p->left=Delete(p->left,q->data);
		}
		else{
			q=preSuc(p->right);
			p->data=q->data;
			p->right=Delete(p->right,q->data);
		}
	}
	return p;
}

class stack{
	public:
	int last=0;
	TreeNode *A[10];
	void push(TreeNode *p){
		A[last]=p;
		last++;
		return;
	}
	TreeNode *pop(){
	 return	A[last--];
	}
	TreeNode *top(){
		return A[last];
	}
};

TreeNode* Createpre(int arr[],int n){
	TreeNode *node;
	int i=0;
	TreeNode *p=new TreeNode(arr[i++]);
	stack st;
	node=p;
	st.push(node);
	while(i<n){
		if(p->data > arr[i]){
			TreeNode *temp=new TreeNode(arr[i++]);
			p->left=temp;
			p=temp;
			st.push(temp);
		}
		else{
			//two case arise if the arr[i] > p->data we have to check range for it
			if(p->data<arr[i] && arr[i]<st.top()->data){
				TreeNode *temp=new TreeNode(arr[i++]);
				p->right=temp;
				st.push(temp);
				p=temp;
			}
			else{
				p=st.pop();
			}
		}
	}
	
	return node;
}

int main(){
	
	int arr[]={30,10,20,15,25,40,45,50};
	TreeNode *pre=Createpre(arr,8);
	Inorder(pre);
   
	return 0;
}
