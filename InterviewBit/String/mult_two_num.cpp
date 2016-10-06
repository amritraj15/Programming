/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 
For example, 
given strings "12", "10", your answer should be “120”.

NOTE : DO NOT USE BIG INTEGER LIBRARIES ( WHICH ARE AVAILABLE IN JAVA / PYTHON ). 
We will retroactively disqualify such submissions and the submissions will incur penalties.


class Solution {
    public:
        std::string multiply(std::string num1, std::string num2) {

            int n1 = num1.size();
            int n2 = num2.size();
            if (n1 == 0 || n2 == 0)     return "0";

            // will keep the result number in vector in reverse order
            std::vector<int> result(n1 + n2, 0);

            int i_n1 = 0; // index by num1
            int i_n2 = 0; // index by num2

            // go from right to left by num1
            for (int i = n1 - 1; i >= 0; i--){
                int carrier = 0;
                int n1 = num1[i] - '0';
                i_n2 = 0;

                // go from right to left by num2
                for (int j = n2 - 1; j >= 0; j--){
                    int n2 = num2[j] - '0';     

                    int sum = n1 * n2 + result[i_n1 + i_n2] + carrier;
                    carrier = sum / 10;
                    result[i_n1 + i_n2] = sum % 10;

                    i_n2++;
                }

                // store carrier in next cell
                if (carrier > 0)
                    result[i_n1 + i_n2] += carrier;

                i_n1++;
            }

            // ignore '0's from the right
            int i = result.size() - 1;
            while (i>=0 && result[i] == 0) i--;

            // if all were '0's - means either both or one of num1 or num2 were '0'
            if(i == -1) return "0";

            // generate the result string
            std::string s = "";
            while (i >= 0) s += std::to_string(result[i--]);

            return s;
        }
};
Close


*/

string Solution::multiply(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,l,m,n,num2,num1,carry=0,temp,cu,pos,cur;
    m = A.size();
    n = B.size();
    if(m==0||n==0) 
        return "";
    string ans(m+n+1,'0');
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    for(i=0;i<n;i++)
    {
        num2=B[i]-'0';
        carry=0;
        
        for(int j=0;j<m;j++)
        {
            num1=A[j]-'0';
            temp=ans[i+j]-'0';
            cur=num1*num2+temp+carry;
            ans[i+j]=cur%10+'0';
            carry=cur/10;
        }
    ans[i+m]=carry+'0';
    }
    reverse(ans.begin(),ans.end());
    
    pos=ans.find_first_not_of('0',0);
    
    if(pos<0||pos>=ans.size())
        pos=ans.size()-1;
        
    return ans.substr(pos,ans.size()-pos);
    }

