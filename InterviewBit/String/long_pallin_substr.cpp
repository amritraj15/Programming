/*
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"
*/

string Solution::longestPalindrome(string A) {
 
    int i,j;
    int n=A.length();
    if(n==1)
        return A;
    string str="";
    int p,q,l=0,start,end;
    for(i=0;i<n-1;i++){
        p=q=i;
        while(p>=0 && q<n && A[p]==A[q]){
            if(q-p+1 > l){
                l=q-p+1;
                start=p;
                end=q;
            }
            p--;q++;
        }
        if(str.length()<l){
            str="";
            for(j=start;j<=end;j++)
                str+=A[j];
        }
        if(A[i]==A[i+1]){
            p=i;q=i+1;
            while(p>=0 && q<n && A[p]==A[q]){
                if(q-p+1 > l){
                    l=q-p+1;
                    start=p;
                    end=q;
                }
                p--;q++;
            }
            if(str.length()<l){
                str="";
                for(j=start;j<=end;j++)
                    str+=A[j];
            }
        }
    }
    
    return str;
}
