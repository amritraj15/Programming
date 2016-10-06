/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4
*/

int Solution::singleNumber(const vector<int> &A) {

    int i,j,k=0,l=0,n,ones=0,twos=0,common_bit;
    n=A.size();
    for( i=0; i< n; i++ )
    {
       
        twos |= ones & A[i] ;
        ones ^= A[i] ;
        common_bit = ~(ones & twos) ;
        ones &= common_bit ;
        twos &= common_bit ;
    }
    return ones;
}
