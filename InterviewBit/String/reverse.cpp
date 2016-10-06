/*
Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".
*/

void Solution::reverseWords(string &A) {

    int i,j,k,l,n;
    string p="",m="";
    
    A+=" ";
    n = A.size();
    for(i=0;i<n;i++)
    {
        if(A[i]!=' ')
        {
            p+=A[i];
        }
        else
        {
            k=i;
            while(A[k]==' ')
                k++;
            
            m = p + " " + m;
            p="";
            i=k-1;
        }
    }
    //cout<<m;
    l = m.size()-1;
    A.clear();
    while(m[l]==' ')
    {
        m.pop_back();
        l--;
    }
    
    A = m;
}
