/*

You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:
- Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.

For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
*/

vector<int> Solution::flip(string A) {
    int i,j,k,l,size,c0=0,c1=0,left=0,right=0,ctr=0,in,total;
    vector <int> ans;
    vector <int> g;
    l=A.size();
    for(i=0;i<l;i++)
    {
        in = A[i] - 48;
        k = (in==1) ? -1 : 1;
        g.push_back(k);
        
        if(in  == 1)
            c1++;
        else
            c0++;
    }
    int cur_left=0,cur_right=0,dif,max_sum=0,cur_sum=0;
    dif=abs(c1-c0);
    
    right = l-1;
    //cout<<c1<<" "<<l;
    if(c1==l)
        return ans;
    else
    {
        for(i=0;i<g.size();i++)
        {
            if(cur_sum + g[i]>=0 ){
                cur_sum+=g[i];
                cur_right=i;
            
            }
            else {
                cur_sum=0;
                cur_left = i + 1;
            }
            
            if(cur_sum>max_sum){
                
                max_sum = cur_sum;
                
                left = cur_left;
                
                right = cur_right;
            }
        }
    }
    ans.push_back(left+1);
    ans.push_back(right+1);
    return ans;
}