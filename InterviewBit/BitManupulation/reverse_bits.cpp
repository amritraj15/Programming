/*
Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000
return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000
*/

unsigned int Solution::reverse(unsigned int A) {
  
    unsigned int k=0,a;
    int i,l,j;
    l=31;
    while(A!=0)
    {
         j = A%2;
         k = k + j*pow(2,l);
         A/=2;
         l--;
    }
    
    //cout<< k;
    return k;
}
