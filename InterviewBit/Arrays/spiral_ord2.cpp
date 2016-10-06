/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
 [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ] 
*/

vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i,j,k,top,bottom,left,right,direction,m,n;
	//len = A.size();
	//cout<<"len " <<len<<"\n";
	int arr[A][A];
	memset(arr,0,sizeof arr);
	m=n=A;
	top=0;
	bottom=m-1;
	left=0;
	right=n-1;
	direction=0;
	vector <int> result;
	vector<vector<int> > ans;
	k=1;
	while(top<=bottom && left<=right)
	{
		if(direction==0)
		{
			for(i=left;i<=right;i++)
			{
				arr[top][i] = k++;
			}
			top++;
			direction=1;
		}
		else if(direction==1)
		{
			for(i=top;i<=bottom;i++)
			{
				arr[i][right]=k++;
			}
			right--;
			direction=2;
		}
		else if(direction==2)
		{
			for(i=right;i>=left;i--)
			{
				arr[bottom][i]=k++;
			}
			bottom--;
			direction=3;
		}
		else if(direction==3)
		{
			for(i=bottom;i>=top;i--)
			{
				arr[i][left]=k++;
			}
			left++;
			direction=0;
		}
	
	}
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            result.push_back(arr[i][j]);
        }
        
        ans.push_back(result);
        result.clear();
    }
	
	return ans;
	
}
