
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        //brute force approach
        //we store all the element of linklist in the vector and question is boil down to 
        //next greater element
        ListNode* p=head;
        vector<int>ans,temp;
        while(p){
            temp.push_back(p->val);
            p=p->next;
        }
        
        //now we search in the temp vector and store ans in ans vector
        for(int i=0;i<temp.size();i++){
            bool flag=true;
            for(int j=i+1;j<temp.size();j++){
                if(temp[i]<temp[j]){
                    ans.push_back(temp[j]);
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(0);
        }
        return ans;
    }
};

//optimal solution using stack

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        //brute force approach
        //we store all the element of linklist in the vector and question is boil down to 
        //next greater element
        ListNode* p=head;
        vector<int>temp;
        while(p){
            temp.push_back(p->val);
            p=p->next;
        }
        
        //now we search in the temp vector and store ans in ans vector
       stack<int>st;
        int n=temp.size();
    vector<int>ans(n);
        for(int i=temp.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=temp[i]){
                st.pop();
            }
            if(st.empty())
                ans[i]=0;
            else
                ans[i]=st.top();
            
            st.push(temp[i]);
        }
        return ans;
    }
};













