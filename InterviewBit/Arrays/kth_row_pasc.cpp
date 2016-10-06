/*
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]


*/

vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> row(A+1);
    int i,j,k;
    row[0] = 1; //First element is always 1
    for(i=1; i<A/2+1; i++){ //Progress up, until reaching the middle value
        row[i] = row[i-1] * (A-i+1)/i;
    }
    for(i=A/2+1; i<=A; i++){ //Copy the inverse of the first part
        row[i] = row[A-i];
    }
    return row;
}
