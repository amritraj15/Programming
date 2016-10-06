/*
Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes
- Length of given string s will always equal to n - 1
- Your solution should run in linear time and space.

Example :

Input 1:

n = 3

s = ID

Return: [2, 3, 1]
*/

vector<int> Solution::findPerm(const string A, int B) {
    
    int i,j,k,l,a,c,n,m;
    vector < int > ans;
    a=B;
    n=1;
    string str="",s1="",s2="";
    l=A.size();
    for(i=0;i<l;i++)
    {
        if(A[i]=='I')
        {
            ans.push_back(n);
            n++;
            
        }
        else{
            ans.push_back(a);
            a--;
        }
    }
    ans.push_back(n);
    return ans;
    
}

