/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
   ListNode *cur=A,*prev=NULL;
    int n=0,i;

    while(cur){
        cur=cur->next;
        n++;
    }
    cur=A;
    if(n <= B)
    {
        A=A->next;
        free(cur);
        return A;
    }
    n=n-B-1;
    while(n--)
    {
        cur=cur->next;
    }
    prev=cur;
    cur=cur->next;
    prev->next=cur->next;
    cur->next=NULL;
    free(cur);
    return A;
}
