/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3
*/
int Solution::singleNumber(const vector<int> &A) {

    int i,j,k=0,n,m;
    n = A.size();
    for(i=0;i<n;i++)
    {
        k=k^A[i];
    }
    return k;
}
