/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int i,j,k,l,t,b,r,dir,m,n;
	m=A.size();
	n=A[0].size();
	//len = A.size();
	//cout<<"len " <<len<<"\n";
	t=0;
	b=m-1;
	l=0;
	r=n-1;
	dir=0;
	//vector <int> result;
	while(t<=b && l<=r)
	{
		if(dir==0)
		{
			for(i=l;i<=r;i++)
			{
				result.push_back(A[t][i]);
			}
			t++;
			dir=1;
		}
		else if(dir==1)
		{
			for(i=t;i<=b;i++)
			{
				result.push_back(A[i][r]);
			}
			r--;
			dir=2;
		}
		else if(dir==2)
		{
			for(i=r;i>=l;i--)
			{
				result.push_back(A[b][i]);
			}
			b--;
			dir=3;
		}
		else if(dir==3)
		{
			for(i=b;i>=t;i--)
			{
				result.push_back(A[i][l]);
			}
			l++;
			dir=0;
		}
	
	}
	
	// DO STUFF HERE AND POPULATE result
	
	
	
	return result;

}
