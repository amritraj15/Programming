
/*
Given a string, find the rank of the string amongst its permutations sorted lexicographically. 
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
The answer might not fit in an integer, so return your answer % 1000003




class Solution {
    public:
        #define MOD 1000003

        void initializeFactorials(int totalLen, vector<int> &fact) {
            long long int factorial = 1;
            fact.push_back(1); // 0!= 1
            for (int curIndex = 1; curIndex < totalLen; curIndex++) {
                factorial = (factorial * curIndex) % MOD;
                fact.push_back(factorial);
            }
            return;
        }

        int findRank(string S) {
            // Initializations
            
            int charCount[256]; // count of characters in S. 
            memset(charCount, 0, sizeof(charCount));
            for (int i = 0; i < S.length(); i++) charCount[S[i]]++;

            vector<int> fact; // fact[i] will contain i! % MOD
            initializeFactorials(S.length() + 1, fact);

            long long int rank =  1;
            for (int i = 0; i < S.length(); i++) {
                // find number of characters smaller than S[i] still left. 
                int less = 0;
                for (int ch = 0; ch < S[i]; ch++) {
                    less += charCount[ch]; 
                }
                rank = (rank + ((long long)fact[S.length() - i - 1] * less)) % MOD;
                // remove the current character from the set. 
                charCount[S[i]]--;
            }
            return rank;
        }
};

*/

long long int fact(long long int n)
{
    return (n <= 1)? 1 :n * fact(n-1);
}
 
long long int findSmallerInRight(string str,long long int low, long long int high)
{
    long long int countRight = 0, i;
 
    for (i = low+1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;
 
    return countRight;
}


int Solution::findRank(string A) {


    long long int len = A.size();
    long long int mul = fact(len);
    long long int rank = 1;
    long long int countRight;
 
    long long int i;
    for (i = 0; i < len; ++i)
    {
        mul /= len - i;
 
        // count number of chars smaller than str[i]
        // fron str[i+1] to str[len-1]
        countRight = findSmallerInRight(A,i,len-1);
 
        rank =(rank +  (countRight * mul)) ;
    }
    rank = rank%1000003;
    int ans = rank;
    return ans;

}
