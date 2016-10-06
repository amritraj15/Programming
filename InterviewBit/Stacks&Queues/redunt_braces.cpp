/*
Write a program to validate if the input string has redundant braces?
Return 0/1 
 0 -> NO 1 -> YES 

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

*/

int Solution::braces(string A) {
   
    stack<char> st;
    int i,j,k,n;
    n = A.size();
            

    for(i=0;i<n;i++)
    {
        if(A[i]==')')
        {
            k=0;
            while(st.top()!='(')
            {
                st.pop();
                k++;
            }
            st.pop();
            if(k<2)
                return 1;
        }
        else
        {
            st.push(A[i]);
        }
        
    }
    
    k = 1;
    
    while(st.size())
    {
        if(st.top()=='(' || st.top()==')')
        {
            k =1;
            break;
        }
        st.pop();
    }
    
    if(!k)
        return 1;
    else
        return 0;
    
}
