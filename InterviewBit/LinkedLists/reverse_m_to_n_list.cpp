/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

If you are still stuck at reversing the full linked list problem, 
then would maintaining curNode, nextNode and a tmpNode help ?

Maybe at every step, you do something like this :

    tmp = nextNode->next;
            nextNode->next = cur;
            cur = nextNode;
            nextNode = tmp;
Now, lets say you did solve the problem of reversing the linked list and are stuck at applying it to current problem. 
What if your function reverses the linked list and returns the endNode of the list. 
You can simply do 
prevNodeOfFirstNode->next = everseLinkedList(curNode, n - m + 1);



class Solution {
public:
 
    // Reverses the linkedList which starts from head, and extends to size nodes. 
    // Returns the end node. 
    // Also sets the head->next as endNode->next. 
    ListNode *reverseLinkedList(ListNode *head, int size) {
    if (size <= 1) return head; 
        ListNode *cur = head, *nextNode = head->next, *tmp;

    for (int i = 0; i < (size - 1); i++) {
        tmp = nextNode->next;
        nextNode->next = cur; 
        cur = nextNode;
        nextNode = tmp; 
    }

    head->next = nextNode;
    return cur;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
    // Introduce dummyhead to not handle corner cases. 
    ListNode* dummyHead = new ListNode(0); 
    dummyHead->next = head; 

    // Figure out the start node of the sublist we are going to reverse
      ListNode* prev = dummyHead;
    ListNode* cur = head; 
    int index = 1;
    while (index < m) {
        prev = cur;
        cur = cur->next;
        index++;
    }

    // At this point, we have start of sublist in cur, prev of startSubList in prev.
    // Lets reverse the sublist now. 
    ListNode* endSubList = reverseLinkedList(cur, n - m + 1);
    prev->next = endSubList; 

    return dummyHead->next;
    }
};


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode* newHead = new ListNode(-1);
    newHead->next = A;
    ListNode* prev = newHead;
    for(auto i = 0 ; i < m-1 ; i++){
        prev = prev->next;
    }
    ListNode* const reversedPrev = prev;
            //position m
    prev = prev->next;
    ListNode* cur = prev->next;
    for(auto i = m ; i < n ; i++){
        prev->next = cur->next;
        cur->next = reversedPrev->next;
        reversedPrev->next = cur;
        cur = prev->next;
    }
    return newHead->next;
}