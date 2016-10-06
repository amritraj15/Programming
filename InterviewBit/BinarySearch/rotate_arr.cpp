/*
Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.


class Solution {
    public:
        int findMin(const vector<int> &A) {
            int low = 0, high = (int)A.size() - 1;
            int len = A.size();
            while (low <= high) {
                if (A[low] <= A[high]) return A[low]; // Case 1
                int mid = (low + high) / 2;
                int next = (mid + 1) % len, prev = (mid + len - 1) % len;
                if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
                    return A[mid];
                else if (A[mid] <= A[high]) high = mid + 1; // Case 3
                else if (A[mid] >= A[low]) low = mid + 1; // Case 4
            }
            return -1;
        }
};


*/

int rotation(const vector<int> &A)
{
    int low=0,high,mid,result=-1,ctr=0,right,left,n;
    n=A.size();
    high = n-1; 
    
    while(low<=high)
    {
        if(A[low]<=A[high])
            return low;
            
        mid = (high+low)/2;
        right = (mid+1)%n;
        left = (mid+n -1)%n;
        
        if(A[mid]<=A[right] && A[mid]<=A[left])
            return mid;
        else if(A[mid]<=A[high])
            high = mid -1;
        else if(A[mid]>=A[low])
            low = mid + 1;
    }
    return -1;
}
int Solution::findMin(const vector<int> &A) {
   
    int ans  = rotation(A);
    if(ans==-1)
        return A[0];
    else
        return A[ans];
    
}
