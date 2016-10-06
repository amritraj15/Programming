/*
Another question which belongs to the category of questions which are intentionally stated vaguely. 
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
*/

int Solution::strStr(const string &haystack, const string &needle) {

    int i,j,k,l,m,n,flag,rem;
    n = haystack.size();
    m = needle.size();
    
    if(n==0 || m==0)
        return -1;
    
    flag=-1;
    for(i=0;i<n;i++)
    {
        
        if(haystack[i]==needle[0]);
        {
            j=0;
            while(j<m && haystack[j+i]==needle[j]) 
                j++;
            if(j==m)
                return i;
        }
    }
    
    return flag;
}
