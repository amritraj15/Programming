/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            int len = num.size();
            int i,j;
            for(i = len - 2; i >= 0 ; i--)
                if(num[i] < num[i+1]) break;

            if (i == -1) {
                reverse(num.begin(), num.end());
                return;
            }

            for(j = len - 1; j > i; j--)
                if(num[j] > num[i]) break;

            swap(num[i], num[j]);
            reverse(num.begin() + i + 1, num.end());
            return;
        }
};

*/

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    /*
                a = a + b + c;
	        b = a - b - c;
	        c = a - b - c;
	        a = a - b - c;
	 */
    vector <int> ans;
    int i,j,k,l,temp,small;
    l=A.size();
    ans=A;
    for(i=l-1; i >=1 ; i--)
	{
        if(A[i]>A[i-1])
			break;
	}
	
	if(i==0)
		sort(A.begin(),A.end());
	else
	{
    	k = A[i-1];
    	small = i;
    	for(j = i + 1 ; j<l; j++)
    	{
    		if(A[j]> k && A[j]< A[small])
    		{
    			small = j;
    		}
    	}
    	temp = A[small];
    	A[small]= A[i-1];
    	A[i-1]= temp;
    	sort(A.begin() + i , A.end());	    
	}

}
