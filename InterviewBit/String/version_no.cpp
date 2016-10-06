/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
*/

string trim(string A)
{
    int m=A.length();
    string temp="";
    int i=0;
    while(i<m && A[i]=='0') 
        i++;
    if(i==m)
        temp="0";
    else {
        while(i<m)
        {
            temp+=A[i];
            i++;
        }
    }
    return temp;
}
string number(string A,int &i)
{
    string temp="";
    while(i<A.length() && A[i]!='.')
    {
        temp+=A[i];
        i++;
    }
    return trim(temp);
}
int Solution::compareVersion(string A, string B) {
    int i=0,j=0;
    string n1="1",n2="1";
    while(i<A.length() || j<B.length())
    {
        n1=number(A,i);
        i++;
        n2=number(B,j);
        j++;
        if(n1.length()==n2.length())
        {
            if(n1>n2)
                return 1;
            else if(n1<n2)
                return -1;
        }
        else
        {
            if(n1.length()>n2.length())
                return 1;
            else 
                return -1;
        }
    }
    return 0;
    
    
}