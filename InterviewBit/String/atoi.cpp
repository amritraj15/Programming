/*
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
*/

int Solution::atoi(const string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
   int i=0;
    while(A[i]==' ')
        i++;
    int sign=1;
    long long ans=0;
    if(A[i]=='-')
    {
        sign=-1;
        i++;
    }
    else if(A[i]=='+')
    {
        sign=1;
        i++;        
    }
    else if(A[i]<48 || A[i]>57)
        return 0;
    while(A[i]>=48 && A[i]<=57)
    {
        ans=(ans<<3)+(ans<<1)+(A[i]&15);
        i++;
        if(ans>INT_MAX)
            break;
    }
    ans*=sign;
    if(ans<INT_MIN)
        return INT_MIN;
    if(ans>INT_MAX)
        return INT_MAX;
    return ans;

}
