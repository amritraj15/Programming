/*


Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

*/


    static bool myfunc(const Interval &a, const Interval &b){
        return (a.start < b.start);
     }
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
       
        int i,j,k,l;
        
        vector<Interval> res;
        intervals.push_back(newInterval);
        
        if (intervals.size()==0){
            return res;
        }
        sort(intervals.begin(),intervals.end(),myfunc);
        res.push_back(intervals[0]);
        l=intervals.size();
        for (int i=1;i<l;i++)
        {
            if (res.back().end>=intervals[i].start)
            {
                res.back().end=max(res.back().end,intervals[i].end);
            }
            else
            {
                res.push_back(intervals[i]);
            }   
        }
        return res;
}