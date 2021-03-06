/*
Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 

class Solution {
    public:
    vector<int> primesum(int N) {
        
        // Generate isPrime List less equal than N
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        // Sieve of Erastothenes
        for(int i = 2; i <= N; i++) {
            if (!isPrime[i]) continue;
            if (i > N / i) break;
            for (int j = i * i; j <= N; j += i) isPrime[j] = false;
        }
        
        for(int i = 2; i <= N; ++i) {
            if(isPrime[i] && isPrime[N - i]) {
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(N - i);
                return ans;
            }
        } 
        
        vector<int> ans; 
        return ans;
    }
};

*/

vector<int> Solution::primesum(int A) {
    
    int i,j,k,l,n,p,m,sq,N;
    N=A;
    vector<bool> isPrime(N + 1, true);
    vector<int> ans; 
    isPrime[0] = false;
    isPrime[1] = false;
         
    
    for(i = 2; i <= N; i++) 
    {
        if (!isPrime[i]) 
            continue;
        if (i > N / i) 
            break;
        for (j = i * i; j <= N; j += i) 
            isPrime[j] = false;
    }
         
    for(i = 2; i <= N; ++i) {
        if(isPrime[i] && isPrime[N - i]) 
        {
            ans.push_back(i);
            ans.push_back(N - i);
            return ans;
        }
    } 
         
    return ans;
    
}
