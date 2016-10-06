#include<bits/stdc++.h>
using namespace std;

int power2(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,l,m,n,num=0;
    n =A.size();
    for(i=0;i<n;i++)
    {
        num = num*10 + (A[i]- '0');
        if(num>INT_MAX)
            return 0;
    }
	//cout<<num;
    m = num;
	m = num && (!(num&(num-1)));

        return m;
}
int main()
{
	int t;
	string n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<< power2(n)<<"\n";
	}
return 0;
}