/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:


class Solution {
    public:
        string convert(string s, int nRows) {

            if (nRows <= 1)
                return s;

            const int len = (int)s.length();
            string *str = new string[nRows];

            int row = 0, step = 1;
            for (int i = 0; i < len; ++i)
            {
                str[row].push_back(s[i]);

                if (row == 0)
                    step = 1;
                else if (row == nRows - 1)
                    step = -1;

                row += step;
            }

            s.clear();
            for (int j = 0; j < nRows; ++j)
            {
                s.append(str[j]);
            }

            return s;
        }

};

*/

string Solution::convert(string A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        int nRows=B;
        vector<string> zz(nRows,"");
        if (nRows==1){return A;}
         
        int i=0; //for string 
        int r=0; //for zz vector
        bool zig = false; // if s[i] is in "/" or "|" direction
        while (i<A.size())
        {
            if (r<nRows && !zig)
            {
                zz[r]+=A[i];
                r++;
                i++;
            }
            else
            {
                if (!zig){
                    zig=true;
                    r--;
                }
                else
                {
                    r--;
                    zz[r] = zz[r]+A[i];
                    if (r==0)
                    {
                        zig=false;r++;
                        
                    }
                    i++;
                }
            }
        }
        string res; //get result;
        for (int i=0;i<zz.size();i++){
            for (int j=0;j<zz[i].size();j++){
                    res = res+ zz[i][j];
            }
        }
        return res;
}
