/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4



*/

/*


class Solution {
public:
    vector<int> repeatedNumber(const vector<int> &V) {
       long long sum = 0;
       long long squareSum = 0;
       long long temp;
       for (int i = 0; i < V.size(); i++) {
           temp = V[i];
           sum += temp;
           sum -= (i + 1);
           squareSum += (temp * temp);
           squareSum -= ((long long)(i + 1) * (long long)(i + 1));
       }
       // sum = A - B
       // squareSum = A^2 - B^2 = (A - B)(A + B)
       // squareSum / sum = A + B
       squareSum /= sum;

       // Now we have A + B and A - B. Lets figure out A and B now. 
       int A = (int) ((sum + squareSum) / 2);
       int B = squareSum - A;

       vector<int> ret;
       ret.push_back(A);
       ret.push_back(B);
       return ret;
    }
};


*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector <int> ans;
    long long int sum=0,i,j,k,l,q,s1,sq1,sq2=0;
    l=A.size();
    for(i=0;i<l;i++)
    {
        sum+=A[i];
        sq2+= A[i] * A[i];
       // printf("a");
        //cout<<l;
    }
    s1 = (l*(l+1))/2;
   // sq1 = (l*(l+1))/2
    sq1 =s1 * (2*l + 1)/3;
   // cout<<sum<<" "<<s1<<" "<<sq1<<" "<<sq2;
   q= (s1-sum);
   k= (sq1- sq2)/q;
   int a1=((k+q))/ 2;
    int b= ((k-q)) / 2;
    
    ans.push_back(b);
    ans.push_back(a1);
    return ans;
}