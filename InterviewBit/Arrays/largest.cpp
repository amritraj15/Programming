/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
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
    /*
    for (it= s.begin(); it != s.end(); it++)
    {		
    
        if ((*it) == '0')							
    	    it = s.erase (it);
    	else
    	    break;
        
    }
    */
    
    int pos = 0;
    
    while (s[pos] == '0' && pos + 1 < s.size()) 
        pos++; 
    return s.substr(pos);  
    
}
