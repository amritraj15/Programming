/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.
*/

string Solution::simplifyPath(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int i,j,k,n;
    
    vector<string> nameVect;
    string name;
 
    A.push_back('/');
    n= A.size();
    for (i = 0; i < n ; i++) {
     
        if (A[i] == '/') 
        {
     
            if (name.size() == 0) 
                continue;
     
            if (name == "..") 
            {
                if (nameVect.size() > 0) 
                    nameVect.pop_back();
     
            } 
             
            else if (name == ".") 
            { 
     
            } 
             
            else {          
                nameVect.push_back(name);
            }
             
            name.clear();
        } 
        else 
        {
            name.push_back(A[i]);
        }
    }
 
    string result;
     
    if (nameVect.empty()) 
        return "/";
     
    for (i = 0; i < nameVect.size(); i++) {
        result.append("/" + nameVect[i]);
    }
     
    return result;
}

