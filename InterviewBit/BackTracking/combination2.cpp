/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]


Recursion ftw.
A thing to note here : 
Some elements can be repeated in the input set. Make sure you iterate over the number of occurrences of those elements to make sure you are not counting the same combinations again.

Once you do that, things are fairly straightforward. You make a recursive call with the remaining sum and make sure the indices are moving forward.



    void doWork(vector<int> &candidates, int index, vector<int> &current, int currentSum, int target, vector<vector<int> > &ans) {
    	if (currentSum > target) {
		return;
	}
	if (currentSum == target) {
		ans.push_back(current);
		return;
	}
	if (index >= candidates.size()) {
		return;
	}

	int endIndex;
	for (endIndex = index + 1; endIndex < candidates.size() && candidates[endIndex] == candidates[endIndex - 1]; endIndex++);
	int countIndex = endIndex - index; 
	for (int i = 0; i <= countIndex; i++) {
		for (int j = 0; j < i; j++) current.push_back(candidates[index]);
		currentSum += i * candidates[index];
		doWork(candidates, endIndex, current, currentSum, target, ans);
		currentSum -= i * candidates[index];
		for (int j = 0; j < i; j++) current.pop_back();
	}
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> current; 
	vector<vector<int> > ans;
	sort(candidates.begin(), candidates.end());
	doWork(candidates, 0, current, 0, target, ans); 
	return ans;
    }


*/


void combination(vector<int> &A, int target, vector<vector<int> > &res, vector<int> &r,int st){
    if (target<0){
        return;
    }
    else
    {
        if (target==0)
        {
            res.push_back(r);
        }
        else
        {
            int pre = -1,i;
            for (i=st;i<A.size();i++){
                if (A[i]!=pre)
                {
                    r.push_back(A[i]);
                    combination(A,target-A[i],res,r,i+1);
                    pre = A[i];
                    r.pop_back();
                }
            }
        }
    }
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    vector<vector<int> > res;
    if (A.size()==0)
    {
        return res;
        
    }
    sort(A.begin(),A.end());
    vector<int> r;
    combination(A,B,res,r,0);
    return res;
}




