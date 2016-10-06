/*
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

 Note: You may not slant the container. 
Example :

Input : [1, 5, 4, 3]
Output : 6

Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6

class Solution {
    public:
        int maxArea(vector<int> &height) {
            int end = height.size() - 1, start = 0;
            int maxVol = 0;

            while(start < end)
            {
                maxVol = max(maxVol, (end - start) * min(height[start], height[end]));

                if (height[start] < height[end]) {
                    start++;
                } else {
                    end--;
                }
            }
            return maxVol;
        }
};
Close


*/

int Solution::maxArea(vector<int> &A) {
   
    int i,j,k,l,m,n,max_area,cur_area,a,b;
    n = A.size();
    max_area=0;i=0;j=n-1;
    while(i < j) {
         
        b = min(A[i], A[j]);
        cur_area = (j - i) * b;
        max_area = max(cur_area, max_area);
        if(A[i] > A[j]) 
            j--;
        else 
            i++;
    }
    return max_area;
    
}