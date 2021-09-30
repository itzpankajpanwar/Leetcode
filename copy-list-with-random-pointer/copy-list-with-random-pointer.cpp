/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node *newHead, *l1, *l2;
    if (head == NULL) return NULL;

    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = new Node(l1->val);
        l2->next = l1->random;
        l1->random = l2;
    }
    
    newHead = head->random;
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->random;
        l2->random = l2->next ? l2->next->random : NULL;
    }
    
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->random;
        l1->random = l2->next;
        l2->next = l1->next ? l1->next->random : NULL;
    }

    return newHead;
    }
};