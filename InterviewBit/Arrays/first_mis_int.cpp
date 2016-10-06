/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

class Solution {
    public:
        int firstMissingPositive(vector<int> &A) {
            int n = A.size();
            for (int i = 0; i < n; i++) {
                if (A[i] > 0 && A[i] <= n) {
                    int pos = A[i] - 1;
                    if (A[pos] != A[i]) {
                        swap(A[pos], A[i]);
                        i--;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (A[i] != i + 1) return (i + 1);
            }
            return n + 1;
        }
};

*/

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,l,n,ma,mi,in,temp;
    
    n= A.size();
    j=0;
        for(i=0;i<n;i++)
        {
            if(A[i]>0 && A[i]<=n)
            {
                if( A[i]-1 != i && A[A[i]-1]!=A[i])
                {
                    temp=A[A[i]-1];
                    A[A[i]-1]=A[i];
                    A[i]=temp;
                    i--;
                }
            }
        }
        for(i=0;i<n;i++)
            if(A[i]!=i+1)
                return i+1;
        return n+1;
    /*
    for(i=0;i<n;i++)
    {
        if(A[i]<0)
        {
           swap(A[i],A[j]);
           j++;
        }
    }
    
   // cout << j << " ";
    for(i=j;i<n;i++)
    {
        if(abs(A[i])-1 <= (n-j) && A[abs(A[i])-1]>0)
        {
            A[abs(A[i])-1] = -A[abs(A[i])-1];
        }
    }
    
    for( i = j ;i< n;i++)
    {
        if(A[i]>0)
            return i+1;
    }
    
    return n+1;
    */
}
