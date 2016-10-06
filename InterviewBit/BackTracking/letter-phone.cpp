/*
Given a digit string, return all possible letter combinations that the number could represent.

class Solution {
    public:
        string charmap[10];

        Solution() {
            charmap[0] = "0";
            charmap[1] = "1";
            charmap[2] = "abc";
            charmap[3] = "def";
            charmap[4] = "ghi";
            charmap[5] = "jkl";
            charmap[6] = "mno";
            charmap[7] = "pqrs";
            charmap[8] = "tuv";
            charmap[9] = "wxyz";
        }

        void generateHelper(string &current, int index, string &digits, vector<string> &ans) {
            if (index == digits.length()) {
                ans.push_back(current);
                return;
            }
            int digit = digits[index] - '0';
            for (int i = 0; i < charmap[digit].length(); i++) {
                current.push_back(charmap[digit][i]);
                generateHelper(current, index + 1, digits, ans);
                current.pop_back();
            }
            return;
        }

        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            string current = "";
            generateHelper(current, 0, digits, ans);
            return ans;
        }
};

*/

void combo(string digits, string r, map<char,vector<char> > &mp, vector<string> &res)
{
    if (digits.empty())
    {
        res.push_back(r);
    }
    else
    {
        vector<char> vec = mp[digits[0]];
        for(int i=0;i<vec.size();i++)
        {
            combo(digits.substr(1),r+vec[i],mp,res);
        }
    }
}
vector<string> Solution::letterCombinations(string A) {

    map<char,vector<char> > mp;
    vector<char> v;
    vector<string> res;
    v.push_back('0');
    mp['0'] = v;
    v.clear();
    v.push_back('1');
    mp['1'] = v;
    v.clear();
    int n=2;
    for (char i='a';i<='z';i++)
    {
        v.push_back(i);
        if (i=='c' || i=='f'|| i=='i'|| i=='l'|| i=='o'|| i=='s'|| i=='v'|| i=='z'){
            mp[char(n+'0')]=v;
            n++;
            v.clear();
        }
    }
         
    
    combo(A,"",mp,res);
    return res;
}
