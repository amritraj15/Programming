/*
Find if Given number is power of 2 or not. 
More specifically, find if given number can be expressed as 2^k where k >= 1.
*/

int Solution::power(string A) {
    int i,j,k,l,m,n,num=0;
    n =A.size();
    for(i=0;i<n;i++)
    {
        num = num*10 + (A[i]- '0');
        if(num>INT_MAX)
            return 0;
    }
	//cout<<num;
    m = num;
	
    if(num==1)
        return 0;
    m = (!(num&(num-1)));
    return m;
    
}
