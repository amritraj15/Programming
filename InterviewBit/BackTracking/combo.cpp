/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,
1. Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
2. Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]


Think in terms of recursion.
For every element, you have 2 options. You may either include the element in your subset or you will not include the element in your subset.
Make the call for both the cases

*/

void combo(vector<vector<int>> &v,vector<int> &row,int i,int n,int k){
    if(k==0){
        v.push_back(row);
        return;
    }
    if(i==n)
        return;
    for(int j=i;j<n;j++){
        row.push_back(j+1);
        combo(v,row,j+1,n,k-1);
        row.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k) {

    vector<vector<int>> v;
    vector<int> row;
    combo(v,row,0,n,k);
    return v;
}
