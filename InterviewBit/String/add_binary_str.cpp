/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.

class Solution {
public:
    string addBinary(string a, string b) {
           string ans = "";
    int ansLen = 0, carry = 0, sum;
    int i = (int)a.length() - 1, j = (int)b.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += (a[i] - '0');
        if (j >= 0) sum += (b[j] - '0');
        ans.push_back((char)('0' + sum % 2));
        carry = sum / 2;
        i--; 
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
    }
};


*/

void reverseStr(string &A){
    int i=0;
    char c;
    int n=A.length();
    for(i=0;i<n/2;i++){
        c=A[i];
        A[i]=A[n-i-1];
        A[n-i-1]=c;
    }
}

string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string str="";
    int i,j,k,m,n,carry=0,sum=0;
    m = A.length();
    n = B.length();

    reverseStr(A);
    reverseStr(B);
    i=0;
    //for(i=0;i<min1;i++)
    while(i<m && i<n)
    {
        sum=(A[i]-'0')+(B[i]-'0')+carry;
        carry=sum/2;
        sum%=2;
        str+=(sum+'0');
        i++;
    }
    while(i<m)
    {
        //for(i=n;i<m;i++)
        sum=(A[i]-'0')+carry;
        carry=sum/2;
        sum%=2;
        str+=(sum+'0');
        i++;
    }
    while(i<n)
    {
        //for(i=m;i<n;i++)
        sum=(B[i]-'0')+carry;
        carry=sum/2;
        sum%=2;
        str+=(sum+'0');
        i++;
               
    }
    if(carry>0)
        str+='1';
    
    reverseStr(str);
    
    return str;
    
}
