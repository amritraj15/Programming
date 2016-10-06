/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]


    void permute(vector<int> &num, int start, vector<vector<int> > &result) {
        if (start == num.size() - 1) {
            result.push_back(num);
            return;
        } 
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);
            permute(num, start + 1, result);
            swap(num[start], num[i]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() == 0)
            return result;
        sort(num.begin(), num.end());
        permute(num, 0, result);
        return result;
    }

*/

void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
    if (k==n)
    {
        res.push_back(num);
    }
    else
    {
        int i,temp;
        for (i=k;i<=n;i++){
            //temp = num[k];
            //num[k]=num[i];
            //num[i]=temp;
            swap(num[k],num[i]);   
            perm(num,k+1,n,res);
                 
            //tmp = num[k];
            //num[k]=num[i];
            //num[i]=tmp;
            swap(num[k],num[i]);
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
   
    vector<vector<int> > res;
    perm(A,0,(A.size()-1),res);
    return res;
   
}

