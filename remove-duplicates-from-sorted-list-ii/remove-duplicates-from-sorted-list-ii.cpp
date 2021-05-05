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
    ListNode* deleteDuplicates(ListNode* head) {
     
    ListNode* ct=head;
    ListNode* old=nullptr;
    while(ct)
    {
        if(ct->next && ct->next->val != ct->val)
        {old = ct; ct=ct->next;}
        else if(ct->next && ct->next->val == ct->val)
        {
            ListNode* pre=ct->next;
            while(pre->next && pre->next->val == pre->val)
                pre=pre->next;
            
            pre=pre->next;
            ct->next=pre;
            if(old!=nullptr)
                old->next=ct->next;
            if(old==nullptr)
            { ct=ct->next;
              head=ct;
            }
            else
                ct=ct->next;
        }
        else 
        { old =ct; ct=ct->next;}
    }
    return old == NULL ? old : head;
    }
};