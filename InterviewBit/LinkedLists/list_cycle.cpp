/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example :

Input : 

                  ______
                 |     |
                 \/    |
        1 -> 2 -> 3 -> 4

Return the node corresponding to node 3.

1) Use Hashing:
What if you could maintain a list of nodes already visited. As soon as you visit a node already visited, you know that there is a cycle.

2) 2 pointer approach ( Floyd’s Cycle-Finding Algorithm ) : 
What if you have 2 pointers which are going at different speed. For arguments sake, lets just say one pointer is going at double the speed of the other. 
Would they meet if there is a cycle ? Are they guaranteed to meet if there is a cycle ? 
What happens if there is no cycle ?

Once you detect a cycle, think about finding the starting point.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
/*
        if (!A)
        {
            return NULL;
        }
        ListNode *p=A, *q=A;
        
        while (1)
        {
            if (p->next!=NULL)
            {
                p=p->next;
                
            }
            else
            {
                return NULL;
                
            }
            if (q->next!=NULL && q->next->next!=NULL)
            {
                q=q->next->next;
                
            }
            else
            {
                return NULL;
                
            }
            if (p==q)
            { 
                q=A;
                while (p!=q){
                    p=p->next;
                    q=q->next;
                }
                return p;
            }
        }
        
*/

   ListNode  *slow_p = A, *fast_p = A;
  
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            fast_p=A;
            while (slow_p!=fast_p){
                slow_p=slow_p->next;
                fast_p=fast_p->next;
            }
            return slow_p;
        }
    }
    return NULL;
}
