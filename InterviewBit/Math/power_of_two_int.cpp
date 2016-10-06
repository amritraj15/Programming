/*
Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. A and P both should be integers.

Example

Input : 4
Output : True  
as 2^2 = 4. 


class Solution {
    public:
        bool isPower(int x) {
            if (x <= 1) return true;
            for (int base = 2; base < x && base < INT_MAX / base; base++) {
                int temp = base; 
                while (temp <= x && temp < INT_MAX / base) {
                    temp *= base;
                    if (temp == x) return true;
                }
            }
            return false;
        }
};
*/

bool Solution::isPower(int A) {
    bool flag=false;
    int i,a;
    double q;
    if(A <= 1)
        return true;
    for(a = 2;a <= sqrt(A);a++)
    {
        q = log(A) / log(a);
        if(q - (int)q < 0.000000001)
            return true;
    }
    return false;
}
