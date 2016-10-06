/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/
  if (A != NULL && A->next != NULL)
  {
      /* Swap the node's data with data of next node */
      swap(A->val, A->next->val);
    
      /* Call pairWiseSwap() for rest of the list */
      swapPairs(A->next->next);
  }  



ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *temp = A;
 
    /* Traverse further only if there are at-least two nodes left */
    while (temp != NULL && temp->next != NULL)
    {
        /* Swap data of node with its next node's data */
        swap(temp->val, temp->next->val);
 
        /* Move temp by 2 for the next pair */
        temp = temp->next->next;
    }
    return A;
}

