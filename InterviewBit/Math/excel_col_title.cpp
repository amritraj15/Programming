/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/

string Solution::convertToTitle(int A) {

    int i,j,k,l,m,n;
    n=A;
    string str="";
    
    while(n!=0){
        
        k = (n-1)%26;
        str= (char)(k+65) + str;
        n=(n-1)/26;
        
    }
    return str;
}