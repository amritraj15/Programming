/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
  
    int i,j,k,l,ctr=0;
    ListNode *current=A;
    ListNode *frwd=A->next;
    while(frwd){
        if(current->val==frwd->val){
            current->next=frwd->next;
            frwd->next=NULL;
            free(frwd);
            frwd=current->next;
        }
        else{
            current=current->next;
            frwd=frwd->next;
        }
    }
    return A;
    
    
}
