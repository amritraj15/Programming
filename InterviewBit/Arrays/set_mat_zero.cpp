/*
Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1
On returning, the array A should be :

0 0 0
1 0 1
1 0 1


class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            int rownum = matrix.size();
            if (rownum == 0)  return;
            int colnum = matrix[0].size();
            if (colnum == 0)  return;

            bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

            // Does first row have zero?
            for (int j = 0; j < colnum; ++j) {
                if (matrix[0][j] == 0) {
                    hasZeroFirstRow = true;
                    break;
                }
            }

            // Does first column have zero?
            for (int i = 0; i < rownum; ++i) {
                if (matrix[i][0] == 0) {
                    hasZeroFirstColumn = true;
                    break;
                }
            }

            // find zeroes and store the info in first row and column
            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            // set zeroes except the first row and column
            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
                }
            }

            // set zeroes for first row and column if needed
            if (hasZeroFirstRow) {
                for (int j = 0; j < colnum; ++j) {
                    matrix[0][j] = 0;
                }
            }
            if (hasZeroFirstColumn) {
                for (int i = 0; i < rownum; ++i) {
                    matrix[i][0] = 0;
                }
            }
        }
};

*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,l,n,m,m1,n1;
    
    m= A.size();
    n= A[0].size();
    vector < int > row(m,0), col(n,0);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(A[i][j]==0){
                
                row[i]=0;
                col[j]=0;
            }
        }
    }
    m1 = row.size();
    n1= col.size();
    /*
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n;j++)
        {
            A[row[i]][j]=0;
        }
    }
    for(i=0;i<n1;i++)
    {
        for(j=0;j<m;j++)
        {
            A[j][col[i]]=0;
        }
    }    
    */
    
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ( row[i] == 0 || col[j] == 0 )
            {
                A[i][j] = 0;
            }
        }
    }
}

