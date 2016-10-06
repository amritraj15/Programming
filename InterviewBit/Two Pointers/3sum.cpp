/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/

int Solution::threeSumClosest(vector<int> &A, int B) {

    sort(A.begin(),A.end());
    int i,j,k,l,m,n,sum,dif,min=INT_MAX,res=0;
    n = A.size();
    for(i=0;i<n-2;i++)
    {
        j = i+1;
        k= n-1;
        while(k>=j)
        {
            sum = A[i]+A[j]+A[k];
            dif = abs(sum - B);
            if( dif== 0)
                return(sum);
            if(dif<min)
            {
                
                res= sum;
                min = dif;
            }
            if(sum<=B)
                j++;
            else 
                k--;
        }
    }
    return res;

}
