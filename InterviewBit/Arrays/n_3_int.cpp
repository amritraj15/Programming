/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 


class Solution {
    public:
        struct eleCount {
            int e; // Element
            int c; // Count
        }
        int repeatedNumber(const vector<int> &V) {
            if (V.size() == 0) return -1;

            /* Step 1: Create a temporary array (contains element
               and count) of size 2. Initialize count of all
               elements as 0 */
            struct eleCount temp[2];
            temp[0].c = temp[1].c = 0; 

            /* Step 2: Process all elements of input array */
            for (int i = 0; i < V.size(); i++) {
                int j;

                /* If arr[i] is already present in
                   the element count array, then increment its count */
                if (temp[0].e == arr[i] || temp[1] == arr[i]) {
                    if (temp[0].e == arr[i]) temp[0].c += 1;
                    else temp[1].c += 1;
                } else {
                /* If arr[i] is not present in temp[] */
                    int l;

                    /* If there is position available in temp[], then place 
                       arr[i] in the first available position and set count as 1*/
                    if (temp[0].c == 0 || temp[1].c == 0) {
                        int index = (temp[0].c == 0) ? 0 : 1;
                        temp[index].e = arr[i];
                        temp[index].c = 1;
                    } else {
                    /* If all the position in the temp[] are filled, then 
                       decrease count of every element by 1 */
                        temp[0].c -= 1;
                        temp[1].c -= 1;
                    }
                }
            }

            /*Step 3: Check actual counts of potential candidates in temp[]*/
            for (int i = 0; i < 2; i++) {
                // Calculate actual count of elements 
                int ac = 0;  // actual count
                for (int j = 0; j < n; j++)
                    if (arr[j] == temp[i].e)
                        ac++;

                // If actual count is more than n/k, then print it
                if (ac > V.size() / 3) return temp[i].e;
            }
            // Not found
            return -1;
        }
};


*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int i,j,k,temp,n,size,a,b,c,a_ct=0,b_ct=0,c_ct=0,cur_a=0, cur_b=0,cur_c=0;
	//n = A.size();

    //int i, j , k ,ans , n , m,ctr,l;
    n= A.size();
    for(i=0;i<n;i++)
	{
    	if(a_ct>0 && A[i]==a)
		{
    		a_ct++;
    	}
		else if(b_ct>0 && A[i]==b)
		{
    		b_ct++;
    	}
		else if(a_ct==0)
		{
    		a=A[i];
    		a_ct=1;
    	}
		else if(b_ct==0)
		{
    		b=A[i];
    		b_ct=1;
    	}
		else
		{
    		a_ct--;
    		b_ct--;
    	}
    }
	int freq=0;
    if(a_ct==0 && b_ct==0)
    	return -1;
    else
	{
		for(i=0;i<n;i++)
		{
			if(A[i]==a)
				freq++;
		}
	}
    if(freq>n/3)
    	return a;
    	
    freq=0;
    for(i=0;i<n;i++)
    {
    	if(A[i]==b)
    		freq++;
    }
    if(freq>n/3)
    	return b;
    return -1;
}
