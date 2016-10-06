/*
Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

class Solution {
    public:
    vector<int> wave(vector<int> Vec) {
        sort(Vec.begin(), Vec.end());
        int N = Vec.size();
        for(int i = 0; i < N - 1; i += 2) {
            swap(Vec[i], Vec[i + 1]);
        }
        return Vec;
    }
};


*/


vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,l,n,m,temp;
    vector < int > res;
    sort(A.begin(),A.end());
    l = A.size();
    for( i = 0 ; i < l-1 ; i++)
    {
        if(i%2==0){
            if(A[i]<A[i+1]){
                iter_swap(A.begin() + i, A.begin() + i+1);
            }
        }
        else{
            if(A[i]>A[i+1]){
                iter_swap(A.begin() + i, A.begin() + i+1);
            }
        }
    }
    for(i=0;i<l;i++)
    {
        res.push_back(A[i]);
    }
    return res;
}
