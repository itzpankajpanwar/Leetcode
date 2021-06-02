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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* root = head;
        vector<int> res;
      
        while(root!=nullptr)
        { res.push_back(root->val);
          root = root->next;
        }
        
        sort(res.begin() , res.end() );
        
        root = head;
        int i=0;
        
        while(root!=nullptr)
        {
           root->val = res[i++];
           root=root->next;
        }
        return head;   
    }
};