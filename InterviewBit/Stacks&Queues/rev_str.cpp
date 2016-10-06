/*
Given a string S, reverse the string using stack.

Example :

Input : "abc"
Return "cba"
*/

string Solution::reverseString(string A) {
    int i,n;
    n=A.size();
    string str="";
    stack<char> s;
	for(i=0;i<n;i++)
	{
		s.push(A[i]);
	}
	for(i=0;i<n;i++)
	{
		A[i]=s.top();
		s.pop();
	}
    return A;
}
