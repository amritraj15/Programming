/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example:

Given the array [-2,1,-3,4,-1,2,1,-5,4],

the contiguous subarray [4,-1,2,1] has the largest sum = 6.

For this problem, return the maximum sum.

Kadane's Algorithm

*/
#include <bits/stdc++.h>
using namespace std;
#define IN(a) scanf("%d",&a)
#define FOR(a,b) for(a=0;a<b;a++)


int maxSubArray(const vector <int> A) {

    int max_so_far = A[0];
   int curr_max = A[0];
    int size = A.size();
   for (int i = 1; i < size; i++)
   {
        curr_max = max(A[i], curr_max+A[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main()
{
	int n,i;	// no of elements in given array
	IN(n);
	vector<int> array(n);
	
	FOR(i,n)
		IN(array[i]);
	printf("%d\n",maxSubArray(array));
}