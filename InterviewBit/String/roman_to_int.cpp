/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System
*/

int Solution::romanToInt(string A) {

    int res = 0, i ;
    
    map<char, int> roman;
    roman['M'] = 1000;
    roman['D'] = 500;
    roman['C'] = 100;
    roman['L'] = 50;
    roman['X'] = 10;
    roman['V'] = 5;
    roman['I'] = 1;

    for (i = 0; i < A.size() - 1; ++i)
    {
        if (roman[A[i]] < roman[A[i+1]])
            res -= roman[A[i]];
        else
            res += roman[A[i]];
    }
    res += roman[A[A.size()-1]];
    return res;
    
    
}
