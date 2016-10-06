/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
*/

int Solution::sqrt(int A) {

   
    long int i,j,start = 1, end = A, ans,mid; 
    if (A == 0 || A == 1) 
       return A;
 
    while (start <= end) 
    {        
         mid = (start + end) / 2;
 
        if (mid*mid == A)
            return mid;

        if (mid*mid < A) 
        {
            start = mid + 1;
            ans = mid;
        } 
        else 
            end = mid - 1;        
    }
    return (int)ans;
}