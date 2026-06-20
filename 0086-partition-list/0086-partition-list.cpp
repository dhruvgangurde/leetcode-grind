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
    ListNode* partition(ListNode* head, int x) {
        ListNode*d1 = new ListNode(0);
        ListNode *d2=new ListNode(0);
        ListNode*prev1=d1;
        ListNode*prev2=d2;
        ListNode*p=head;
        while(p){
            ListNode*q=p->next;
            p->next=nullptr;
            if(p->val<x){
                prev1->next=p;
                prev1=prev1->next;
            }else{
                prev2->next=p;
                prev2=prev2->next;
            }
            p=q;
        }
        prev1->next=d2->next;
        head=d1->next;
        delete d1;
        delete d2;
        return head;
    }
};