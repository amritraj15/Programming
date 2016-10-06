/*
Reverse a linked list using recursion.

Example :
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
ListNode *head;

void reverse(ListNode *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse(p->next);
    ListNode *q = p->next;
    q->next = p;
    p->next = NULL;
}

ListNode* Solution::reverseList(ListNode* A) {
    
    reverse(A);
    return head;
}
