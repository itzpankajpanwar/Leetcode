/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    if(head==nullptr)
        return nullptr;
    ListNode *slow=head;
    ListNode *fast=head;
    do
    {   
        if(slow->next)
            slow=slow->next;
        else
            return NULL;
        if(fast->next)
            if(fast->next->next)
                fast=fast->next->next;
            else
                return NULL;
        else
            return NULL;
    }while(slow!=fast);
        
    fast=head;
        
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
    
    }
};