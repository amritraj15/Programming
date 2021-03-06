/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isPalindrome(string A) {
    string str="";
   int i,n;
    n=A.size();
   for(i=0;i<n;i++)
   {
       if(A[i]-'a'>=0 && A[i]-'a'<26)
            str+=A[i];
        else if(A[i]-'A'>=0 && A[i]-'A'<26)
        {
            A[i]=A[i]-'A'+'a';
            str+=A[i];
        }
        else if(A[i]-'0'>=0 && A[i]-'0'<=9)
        {
            str+=A[i];
        }
   }
   
   n=str.size();
   for(i=0;i<n/2;i++)
   {
       if(str[i]!=str[n-i-1])
        return 0;
   }
   return 1;
}
