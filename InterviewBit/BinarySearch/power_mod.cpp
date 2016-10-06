/*
Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.
*/

int Solution::pow(int x, int n, int d) {
   long long int res = 1,y; 
    y=x%d;
    if(x==0)
        return 0;
    if(n==0 || x==1)
        return 1;
    if(y<0) 
        y=y+d ;
    while (n > 0)
    {
        if (n%2== 1)
            res = (res*y)%d;
 
        n/=2; 
        y = (y*y)%d;  
        if(y<0)
            y+=d;
    }

        return (int)res;
    
}
