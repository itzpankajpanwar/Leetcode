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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< int , vector<int> , greater<int> > minh;
        for(auto &x:lists)
            while(x!=nullptr)
            { minh.push(x->val); x=x->next; }
        
        if(minh.size()==0) return nullptr;
        
        ListNode *root=new ListNode(minh.top());
        minh.pop();
        ListNode* cr =root;
        while(minh.size() >0)
        {
            ListNode *temp = new ListNode(minh.top());
            minh.pop();
            cr->next = temp;
            cr = cr->next;
        }
        return root;
        }
};