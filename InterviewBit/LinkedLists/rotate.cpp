/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    int i,j,k,len;
    if(A==NULL || B==0) 
        return A;
        
    ListNode *cur=A;
    len=1;
    while(cur->next!=NULL){
        cur=cur->next;
        len++;
    }
    B%=len;
    
    k =len-B-1;
    ListNode *pre = A;
    while(k--)
        pre = pre->next;
        
    cur->next = A;
    A = pre->next;
    pre->next = NULL;
    return A;
    
}
