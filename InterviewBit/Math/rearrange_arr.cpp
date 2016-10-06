/*
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
*/

void Solution::arrange(vector<int> &A) {
 int i,j,n;
    n=A.size();
    for (i=0; i < n; i++)
        A[i] += (A[A[i]]%n)*n;
 
    for (i=0; i<n; i++)
        A[i] /= n;
}