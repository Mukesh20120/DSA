//brute force approach using vector

class Solution {
    private:
       vector<int>ans;
public:
    Solution(ListNode* head) {
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
    }
    
    int getRandom() {
        int n=ans.size();
        int l=(rand()%n);
        return ans[l];
    }
};

//other solution using reservoir sampaling algorithm


class Solution {
    private:
    //make a node to traverse
    ListNode *t;
public:
    Solution(ListNode* head) {
        t=head;
    }
    
    int getRandom() {
        ListNode* p=t;
        int ans=0;
        int i=1;
        while(p){
            if(rand()%i==0){
                ans=p->val;
                i++;
                p=p->next;
            }
        }
        return ans;
    }
};

//other solution using simple linklist height and move upto that height

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
    private:
    //make a node to traverse
    int h=0;
    ListNode *t;
public:
    Solution(ListNode* head) {
        t=head;
        while(t){
            h++;
            t=t->next;
        }
        t=head;
    }
    
    int getRandom() {
        ListNode* p=t;
        int l=rand()%h;
        while(l){
            p=p->next;
            l--;
        }
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */


