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
    ListNode *last=NULL;
public:
    int leng(ListNode *p){
        int len=0;
        while(p){
            len++;
            last=p;
            p=p->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        int len=leng(head);
        if(k==len)return head;
        if(k>len)
            k=k%len;
        //now we have to seprate the linkedlist
        ListNode *p=head;
        for(int i=1;i<len-k;i++)
            p=p->next;
        last->next=head;
        head=p->next;
        p->next=NULL;
        return head;
    }
};