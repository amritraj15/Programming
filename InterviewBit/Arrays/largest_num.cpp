/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

       static bool compareNum(string a, string b) {
            return a + b > b + a;
        }

        string largestNumber(const vector<int> &num) {
            string result;
            vector<string> str;
            for (int i = 0; i < num.size(); i++) {
                str.push_back(to_string(num[i]));
            }
            sort(str.begin(), str.end(), compareNum);
            for (int i = 0; i < str.size(); i++) {
                result += str[i];
            }

            int pos = 0;
            while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
            return result.substr(pos);
        }

*/
bool myfunction (string i,string j) { return (i+j>j+i); }
string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> arr;
    string::iterator it;
    string s="",s1="0";
    int i,j,k,l;
    l=A.size();

    vector<string> str;
    for (i = 0; i < l; i++) {
        str.push_back(to_string(A[i]));
    }
    sort(str.begin(),str.end(),myfunction);
    for(i=0;i<l;i++)
    {
        s+=str[i];
    } 

    
    int pos = 0;
    
    while (s[pos] == '0' && pos + 1 < s.size()) 
        pos++; 
    return s.substr(pos);  
    
}
