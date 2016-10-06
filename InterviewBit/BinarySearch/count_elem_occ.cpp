/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.

*/

int binary(const vector<int> &A,int B,bool flag)
{
    int low=0,high,mid,result=-1,ctr=0;
    high = A.size()-1; 
    while(low<=high)
    {
        mid = low + (high - low)/2;
        if(A[mid]==B)
        {
            result=mid;
            if(flag)
                low = mid + 1;
            else
                high = mid -1;
            
        }
        else if(B<A[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    return result;
}


int Solution::findCount(const vector<int> &A, int B) {
    int r1,r2,ans;
    r1 = binary (A, B, true);
    if(r1==-1)
        return 0;
    r2 = binary( A, B, false);
    ans = abs(r1- r2) + 1;
    return ans;
    
}
