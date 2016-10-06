/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Example:

Input : A : [4, 5, 2, 10]
Return : [-1, 4, -1, 2]
*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    
    
    int i,j,k,l,n;
    
    n = A.size();
    stack <int> st;
    vector < int > ans(n,-1);
    
    if(n==1)
        return ans;
        
    //st.push(A[0]);
    
    for (i=0; i<n; i++)
    {

        while (!st.empty() && st.top() >= A[i])
            st.pop();
 
        if (st.empty())
            ans[i] =-1;
        else  
            ans[i] = st.top();
 

        st.push(A[i]);
    }
    return ans;
    
    
}
