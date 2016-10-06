/*


Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


*/

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > ans;
    int i,j,k,n;
    n=1;
    if(A==0)
        return ans;
        
    vector<int> v1;
    v1.push_back(1);
    ans.push_back(v1);
    
    if(A==1)
        return ans;
    
    k=A-1;
    
    while(n<=k)
    {
        vector<int> row(n+1);
        row[0] = 1; //First element is always 1
        for(i=1; i<n/2+1; i++){ //Progress up, until reaching the middle value
            row[i] = row[i-1] * (n-i+1)/i;
        }
        for(i=n/2+1; i<=n; i++){ //Copy the inverse of the first part
            row[i] = row[n-i];
        }
         //return row;  
        ans.push_back(row);
        row.clear();
        n++;
    }
    return ans;
    
}