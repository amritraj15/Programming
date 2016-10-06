/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


   vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > solutions;
        vector<int> solution(n);
        solveNQueensImpl(0, solution, solutions);
        return solutions;
    }
    
    void solveNQueensImpl(int row, vector<int> &solution, vector<vector<string> > &solutions) {
        int n = solution.size();
        if (row == n) {
            solutions.push_back(solToStrings(solution));
            return;
        }
        // For each column...
        for (int j = 0; j < n; ++j) {
            // Skip if there is another queen in this column or diagonals
            if (isAvailable(solution, row, j)) {
                solution[row] = j;
                solveNQueensImpl(row + 1, solution, solutions);
            }
        }
    }

    bool isAvailable(const vector<int> &solution, int i, int j) {
        for (int k = 0; k < i; ++k) {
            if (j == solution[k] || i + j == k + solution[k] || i - j == k - solution[k]) return false;
        }
        return true;
    }

    vector<string> solToStrings(const vector<int>& sol) {
        int n = sol.size();
        vector<string> sol_strings(n);
        for (int i = 0; i < n; ++i) {
            sol_strings[i] = string(n, '.');
            sol_strings[i][sol[i]] = 'Q';
        }
        return sol_strings;
    }


*/


int a[30];
int place(int pos)
{
	int i;
	for(i=1;i<pos;i++)
	{
		if( (a[i]==a[pos]) || ( (abs(a[i]-a[pos])==abs(i-pos)) ) )
			return 0;
	}
	return 1;
}
/*
void print_sol(int n)
{
	int i,j;
	count++;
	//printf("\nSolution #%d:\n",count);
	vector < string > temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i]==j)
			{
				//printf("Q\t");
				temp.push_back("Q");
			}
			else
			{
				//printf("*\t");
				temp.push_back(".");
			}
		}
		printf("\n");
	}
}
*/

    vector<vector<string> > res;
     
    void printres(vector<int> A,int n){
        vector<string> r;
        for(int i=0;i<n;i++){
            string str(n,'.');
            str[A[i]]='Q';
            r.push_back(str);
        }
        res.push_back(r);
    }
     
     
    bool isValid(vector<int> A, int r){
        for (int i=0;i<r;i++){
            if ( (A[i]==A[r])||(abs(A[i]-A[r])==(r-i))){
                return false;
            }
        }
        return true;
    }
     
    void nqueens(vector<int> A, int cur, int n){
        if (cur==n){printres(A,n);}
        else{
            for (int i=0;i<n;i++){
                A[cur]=i;
                if (isValid(A,cur)){
                    nqueens(A,cur+1,n);
                }
            }
        }
    }

vector<vector<string> > Solution::solveNQueens(int A) {

        res.clear();
        vector<int> Q(A,-1);
        nqueens(Q,0,A);
        return res;
    
}


