/*


Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]

    NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output. 


*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,l,m,n;
    vector <int> ans;
    m = A.size();
    n = B.size();
    l = m>n?m:n;
    i=0;j=0;
    while(i<m && j<n)
    {
        if(A[i]==B[j])
        {
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i]>B[j])
        {
            j++;
        }
        else if(A[i]<B[j])
        {
            i++;
        }
    }
    
    return ans;
}