/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/


/*

Reverse the digits of the number to make your life easier.

Maintain a carry which is initialized to 1 ( Denoting that we need to add one to the number ).
Run a loop on the digit array ( which is now reversed ), and add carry to the current digit. If the digit D exceeds 10 on doing so, store the last digit in current position ( D % 10 ), and make carry = rest of the digits ( D / 10 ). Continue the process till you have covered all the digits.
Now if at the end, carry = 0, we are done, and we can return the array.

If not, we need to add one more digit, with carry in it.




class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            reverse(digits.begin(), digits.end());
            vector<int> ans;
            int carry = 1;
            for (int i = 0; i < digits.size(); i++) {
                int sum = digits[i] + carry;
                ans.push_back(sum%10);
                carry = sum / 10;
            }
            while (carry) {
                ans.push_back(carry%10);
                carry /= 10;
            }
            while (ans[ans.size() - 1] == 0 && ans.size() > 1) {
                ans.pop_back();
            }
            reverse(ans.begin(), ans.end());
            reverse(digits.begin(), digits.end());
            return ans;
        }
};



*/


Vector<int> Solution::plusOne(vector<int> &A) {

    vector < int > ans;
    int i,j,k,l,q,carry=0;
    l=A.size();
    q=A[l-1]+1;
    if(q>9)
    {
        carry=q/10;
    }
    ans.push_back(q%10);
    for(i=l-2;i>=0;i--)
    {
        q=A[i]+carry;
		if(carry>0)
        {
            ans.push_back(q%10);
            carry=q/10;
        }
        else
        {
            ans.push_back(q);
        }
    }
    if(carry>0)
        ans.push_back(carry);
    l=ans.size();
    for(i=l-1;i>=0;i--)
    {
        if(ans[i]==0)
            ans.pop_back();
        else
            break;
    }

    
    reverse(ans.begin(), ans.end());
    return ans;
}