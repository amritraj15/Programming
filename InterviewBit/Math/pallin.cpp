/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.

Example :

Input : 12121
Output : True

Input : 123
Output : False
*/

bool Solution::isPalindrome(int A) {
 
    bool ans= true;
    int i,j,k,l,m,n=0;
    m=A;
    //string s = to_string(A);
    //n= s.size();
    //cout<<s;
    if(A<0)
        return 0;
    while(m!=0)
    {
        n = n*10 + m%10;
        m/=10;
    }
    if(n==A)
        return 1;
    else
        return 0;
       
}
