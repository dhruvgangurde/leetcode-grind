/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
uses extra space
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        while(temp){
            if(mpp.find(temp) == mpp.end())
                mpp[temp]++;
            else
                return temp;

            temp = temp->next;
        }
        return nullptr;
    }
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head, ListNode* &fast, ListNode* &slow) {
        if(head == NULL || head->next == NULL)
            return false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;   
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(!hasCycle(head, fast, slow))
            return nullptr;
        slow = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};