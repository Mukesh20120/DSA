//brute force approach

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //what will be the brute force approach is we use two loop
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
           int cnt=0;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[i]){
                  cnt++;
                }
            }
            ans[i]=cnt;
        }
        return ans;
    }
};


//better approach using binary search tree concept

class Node{
    public:
        int val;
        int cnt;
       Node *left;
       Node *right;
    Node(int v){
        val=v;
        cnt=0;
        left=right=NULL;
    }
};

int add(Node *&root,int v,int total){
    if(root==NULL){
        root=new Node(v);
        return total;
    }
    if(root->val < v)
        return root->cnt+add(root->right,v,total+1);
     root->cnt+=1;
    return add(root->left,v,total);
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        Node *root=NULL;
        for(int i=n-1;i>=0;i--){
            ans[i]=add(root,nums[i],0);
        }
        return ans;
    }
};

//optimal approach based on merge sort algorithm
typedef pair<int,int> pa;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        vector<pa>val;
        //pushing all the element with index in val
        for(int i=0;i<n;i++)
            val.push_back({nums[i],i});
        mergesort(val,0,n-1,result);
        
        return result;
    }
    void mergesort(vector<pa>&val,int st,int en,vector<int>&result){
        if(st>=en)return;
        int mid=st+(en-st)/2;
        mergesort(val,st,mid,result);
        mergesort(val,mid+1,en,result);
        
        int left=st;
        int right=mid+1;
        vector<pa>merge;
        int cnt=0;
        while(left<mid+1 && right<=en){
            if(val[left].first>val[right].first){
                cnt++;
                merge.push_back(val[right]);
                right++;
            }
            else{
                result[val[left].second]+=cnt;
                merge.push_back(val[left]);
                left++;
            }
        }
        while(left<mid+1){
             result[val[left].second]+=cnt;
                merge.push_back(val[left]);
                left++;
        }
        while(right<=en){
            merge.push_back(val[right]);
            right++;
        }
        
        //updating the val vector as merge
        int start=st;
        for(pa it: merge){
            val[start].first=it.first;
            val[start].second=it.second;
            start++;
        }
    }
};