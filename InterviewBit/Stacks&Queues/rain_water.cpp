/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example :

Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

int Solution::trap(const vector<int> &A) {
   
    int i,j,k,l,m,n,sum=0,ans=0;
    n = A.size();
    int left[n];
    int right[n];

    //left.push(A[0]);
    left[0]=A[0];
    for(i=1;i<n;i++)
    {
        left[i] = max(left[i-1],A[i]);
        //left.push(k);
    }
    right[n-1] = A[n-1];
    for(i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],A[i]);
    }
    
    //for(i=n-1;i>=0;i--)
    for(i=0;i<n;i++)
    {
        ans+= min(left[i],right[i]) - A[i];
        //left.pop();
    }
    return ans;
}
