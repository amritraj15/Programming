/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

int Solution::searchInsert(vector<int> &A, int B) {
    int low=0,high,mid,result=-1,ctr=0;
    high = A.size()-1; 
    
    while(low<=high)
    {
        mid = low + (high - low)/2;
        if(A[mid]==B)
            return mid;
        else if(B<A[mid])
        {
            high = mid -1;
           
        }
        else
        {
            low = mid+1 ;
            
        }
    }
    return low;

    
}
