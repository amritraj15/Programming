/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 

*/

int Solution::titleToNumber(string A) {

    string str="\0";
    int i,j,k,l,n,ans=0;
    n=A.size();
    for(i=n-1;i>=0;i--)
    {
        if(A[i]>='A' && A[i]<='Z')
        {
            ans+=(int)(A[i]-64)*pow(26,((n-1)-i));
            
        }
    
    }       

    return ans;
    //cout<<ans;
}
