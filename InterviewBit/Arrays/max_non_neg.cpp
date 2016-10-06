/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].

The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index
*/

vector<int> Solution::maxset(vector<int> &A) {
	long long int n,i,j,k,len;
	len = A.size();
	//cout<<"len " <<len<<"\n";
	long long int cur_right=0;
	long long int cur_left=0;
	long long int max_right=-1;
	long long int max_left=-1;
	long long int max_sum=0;
	long long int cur_sum=0;
	
	while(cur_right<len)
	{
		if(A[cur_right]<0){
			
			cur_left = cur_right + 1;
			cur_sum = 0;
		}
		else{
			
			cur_sum+=(int)A[cur_right];
			if(cur_sum > max_sum)
			{
				max_sum = cur_sum;
				max_left = cur_left;
				max_right = cur_right+1;
			}
			else if( cur_sum == max_sum)
			{
				if(cur_right + 1 - cur_left > max_right - max_left)
				{
					max_right = cur_right+1;
					max_left = cur_left;
				}	
			}
		
		}
		cur_right++;
	}
	vector < int> ans;
	if(max_right==-1 || max_left==-1)
	{
		return ans;
	}
	
	//cout<<"l = "<<max_left<<"  r = "<<max_right<<"\n";
	
	for(i=max_left ;i<max_right; i++)
		ans.push_back((int)A[i]);
	
	return ans;
    
}


