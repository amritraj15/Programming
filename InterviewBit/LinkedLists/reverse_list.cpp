/*
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode *current, *nxt, *prev;
    current = A;
    prev= NULL;
    
    while(current!=NULL)
    {
        nxt = current->next;
        current->next = prev;
        
        prev= current;
        current = nxt;
    }
    return prev;
}
