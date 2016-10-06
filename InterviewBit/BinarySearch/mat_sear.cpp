/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
*/

int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    int m,n,in,ans,temp,i,j,low,high,mid;
    m = A.size();
    n= A[0].size();
    for(i=0;i<m;i++)
    {
        if(B>=A[i][0]&& B<=A[i][n-1])
        {
            low=0;
            high = n-1;
            while(low<=high)
            {

                mid = low + (high - low)/2;
                if(A[i][mid]==B)
                    return 1;
                else if(B<=A[i][mid])
                    high = mid -1;
                else
                    low = mid + 1;
            
            }
        }
    }
    return 0;
}
