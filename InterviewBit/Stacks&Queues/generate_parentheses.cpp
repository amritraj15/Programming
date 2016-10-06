/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

int Solution::isValid(string A) {
       stack<char> st;
        for (int i=0;i<A.size();i++){                    
            if ((A[i]=='(') ||(A[i]=='[') ||(A[i]=='{')) 
            {
                st.push(A[i]);
                
            }
            else{   
                if (st.empty()){return false;}
                if ((A[i]==')') && (st.top()!='(')) {return false;}
                if ((A[i]=='{') && (st.top()!='}')) {return false;}
                if ((A[i]=='[') && (st.top()!=']')) {return false;}
                st.pop();
            }
            
        }
        return st.empty();
    }
