/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1
*/

int Solution::trailingZeroes(int A) {
   int i,j,k,c,m,n,temp,x,ctr=0;
    
    n= A;
    while(n!=0)
    {
        c = n/5;
        ctr+=c;
        n = c;
    }
	return ctr;
}