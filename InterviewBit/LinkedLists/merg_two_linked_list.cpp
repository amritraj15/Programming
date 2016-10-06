/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {

ListNode *result = NULL;
 
  /* Base cases */
  if (A == NULL) 
     return(B);
  else if (B==NULL) 
     return(A);
 
  /* Pick either a or b, and recur */
  if (A->val <= B->val) 
  {
     result = A;
     result->next = mergeTwoLists(A->next, B);
  }
  else
  {
     result = B;
     result->next = mergeTwoLists(A, B->next);
  }
  return(result);
    
    
}
