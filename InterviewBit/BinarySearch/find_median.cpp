/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
*/

class Solution {
    public:
        double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
            int m = A.size(), n = B.size();
            if (m > n) return findMedianSortedArrays(B, A);
            int imin, imax, i, j; 
            imin = 0;
            imax = m;
            while (imin <= imax) {
                i = (imin + imax)/2;
                j = (m+n+1)/2 - i;
                if (j > 0 && i < m && B[j - 1] > A[i]) {
                    imin = i + 1;
                } else if (i > 0 && j < n && A[i - 1] > B[j]) {
                    imax = i - 1;
                } else {
                    // Figure out median now. 
                    int median1 = 0, median2 = 0;
                    if (i == 0) {
                        median1 = B[j - 1];
                    } else if (j == 0) {
                        median1 = A[i - 1];
                    } else {
                        median1 = max(A[i - 1], B[j - 1]);
                    }
                    if ((m+n) % 2 == 1) {
                        return 1.0 * median1;
                    }
                    if (i == m) {
                        median2 = B[j];
                    } else if (j == n) {
                        median2 = A[i];
                    } else {
                        median2 = min(A[i], B[j]);
                    }
                    return 1.0 * (median1 + median2) / 2.0;
                }
            }
            return -1.0;
        }

};



double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m,n,i,j,k=0,l,r,mid;
    n = A.size();
    m = B.size();

   if(n==0)
   {
        if(m&1)
            return (double)B[m/2];
        return (double)(B[m/2-1]+B[m/2])/2; 
   }
   if(m==0)
   {
       if(n&1)
            return (double)A[n/2];
        return (double)(A[n/2-1]+A[n/2])/2; 
   }
   int medianIndex,imedian,medianValue,median;
   imedian=-1;
   medianValue;
   bool first=1;
    l=0; r=n-1;
    while(l<=r)
    {
        mid=(l+r)>>1;
        medianIndex=(n+m)/2-mid;
        if(medianIndex>=0 && medianIndex<m)
        {
           if(A[mid]<=B[medianIndex])
           {
               if(medianIndex==0 || (medianIndex>0 && B[medianIndex-1]<=A[mid]))
               {
                    median=mid;
                    medianValue=A[mid];
                    l=n;
               }
               else 
                l=mid+1;
           }
           else 
                r=mid-1;
        }
        else if(medianIndex==m)
        {
            if(A[mid]>=B[medianIndex-1])
            {
                median=mid;
                medianValue=A[mid];
                l=n;
            }
            else 
                l=mid+1;
        }
        else if(medianIndex<0) 
            r=mid-1;
        else 
            l=mid+1;
    }
    if(median < 0)
    {
        first=0;
        l=0;r=m-1;
        while(l<=r)
        {
            mid=(l+r)>>1;
            medianIndex=(n+m)/2-mid;
            if(medianIndex>=0 && medianIndex<n)
            {
               if(B[mid]<=A[medianIndex])
               {
                   if(medianIndex==0 || (medianIndex>0 && A[medianIndex-1]<=B[mid]))
                   {
                        median=mid;
                        medianValue=B[mid];
                        l=m;
                   }
                   else 
                        l=mid+1;
               }
               else 
                    r=mid-1;
            }
            else if(medianIndex==n)
            {
                if(B[mid]>=A[medianIndex-1])
                {
                    median=mid;
                    medianValue=B[mid];
                    l=m;
                }
                else 
                    l=mid+1;
            }
            else if(medianIndex<0) 
                r=mid-1;
            else 
                l=mid+1;
        }
    }
    if((m+n)&1)
        return (double)medianValue;
    int value1,value2;
    if(first)
    {
        if(median==0)
            value1=INT_MIN;
        else 
            value1=A[median-1];
         if(B[0]>medianValue)
            return (double)(medianValue+value1)/2;
        l=0;r=m-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(B[mid]==medianValue){
                r=mid;
                l=m;
            }else if(B[mid]<medianValue)
                l=mid+1;
            else r=mid-1;
        }
        value2=B[r];
    }else{
        if(median==0)
            value1=INT_MIN;
        else value1=B[median-1];
        if(A[0]>medianValue)
            return (double)(medianValue+value1)/2;
        l=0;r=n-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(A[mid]==medianValue){
                r=mid;
                l=n;
            }else if(A[mid]<medianValue)
                l=mid+1;
            else r=mid-1;
        }
        value2=A[r];
    }
    return (double)(medianValue+max(value1,value2))/2;
    
}

