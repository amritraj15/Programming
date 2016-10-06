/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1
*/

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int repeatedNumber(const int* A, int n1) {
    /*
        int i,j,k,temp,n,size;
         int result=0;
        for (i=0; i<n1;i++){
            result^=A[i];
        }

        for (i=1; i<n1; i++){
            result^=i;
        }
        return result;
    */
        int i,j,k,temp,n,size;
        int result=0;
        for (i=0; i<n1;i++){
			while(A[A[i]] != A[i])
				swap(A[i],A[A[i]]);
            //result^=A[i];
        }
		//cout<<"result "<< result;
        for (i=1; i<n1; i++){
			if(A[i] !=i)
				return A[i];
            //result^=i;
        }
}
