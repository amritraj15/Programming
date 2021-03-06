/*
We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.

You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 109+7.

For example,

A=[1, 3, 5]

We return

f(1, 1) + f(1, 3) + f(1, 5) + 
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =

0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8

typedef long long LL;
#define MOD 1000000007ll
int Solution::cntBits(vector<int> &A) {
    int ans=0,n=A.size();

    //traverse over all bits
    for(int i=0; i<31; i++){

        //count number of elements with ith bit = 0
        LL cnt=0;
        for(int j=0; j<n; j++)
            if((A[j]&(1<<i)))cnt++;

        //add to answer cnt*(n-cnt)*2
        ans += (cnt*((LL)n-cnt)*2)%MOD;
        if(ans>=MOD)ans-=MOD;

    }

    return ans;
}

*/

#define MOD 1000000007
int Solution::cntBits(vector<int> &A) {
    
    long long int i,j,k=0,l,m,n,ans=0,count,even,odd;
    n = A.size();

    while(k<n)
    {
        even=0;odd=0;
        k=0;
        for(j=0;j<n;j++)
        {
            if(A[j]&1)
                odd++;
            else 
                even++;
                
            if(A[j]==0)
                k+=1;
            A[j]=A[j]>>1;
        }
        ans+=(odd*even);
        ans%=MOD;
    }
    ans%=MOD;
    ans=(ans<<1);
    ans%=MOD;
    return (int)ans;
}
