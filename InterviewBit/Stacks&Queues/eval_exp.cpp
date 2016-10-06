/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

int Solution::evalRPN(vector<string> &A) {

    stack <int> st;
    int i,j,k,n,op1,op2,a;
    n= A.size();
    for(int i=0;i<n;i++)
    {
       if(A[i][0]=='-' && A[i].length()>1)
       {
           a=stoi(A[i],nullptr,10);
           st.push(a);
           
       }
       else if(A[i][0]-'0'<=9 &&A[i][0]-'0'>=0)
            st.push(stoi(A[i],nullptr,10));
        else{
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            switch(A[i][0])
			{
				case '+':st.push(op1+op2);
						break;
				case '-':st.push(op1-op2);
						break;
				case '*':st.push(op1*op2);
						break;
				case '/':st.push(op1/op2);
						break;
			}
        }
   }
   k=st.top();
   st.pop();
   return k;
}
