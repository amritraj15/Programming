/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int lengthList(ListNode *head) 
{
    int len = 0;
    while(head!=NULL)
    {
        head=head->next;
        len++;
    }
    return len;
}
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m,n,i,j,d;
    m = lengthList(A);
    n = lengthList(B);
    
    
    d = n-m;
    
    if(m>n){
        ListNode *temp = A;
        A=B;
        B=temp;
        d=m-n;
    }
    for(i=0;i<d;i++){
        //adrs.insert(B);
        B=B->next;
    }
    
    while(A!=NULL && B!=NULL)
    {
        if(A==B)
            return A;
        
        A=A->next;
        B=B->next;
    }
    return NULL;
}
