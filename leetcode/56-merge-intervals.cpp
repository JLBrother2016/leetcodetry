#include "../leetcodeutil.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
        	return {};
        // lambda表达式
        sort(intervals.begin(), intervals.end(),
        	 [](const Interval& a, const Interval& b){
        	 	return a.start < b.start;
        	 }); //先将所有Intervals排序, 再将有重叠的部分合并
        vector<Interval> ans;
        for(const auto& interval : intervals) {
        	if(ans.empty() || interval.start > ans.back().end) 
        		ans.push_back(interval);
        	else
        		ans.back().end = max(ans.back().end, interval.end);
        }

        return ans;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        auto cmp = [](Interval i1, Interval i2){return i1.start < i2.start;};
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> rlt;
        if (intervals.size() < 2) return intervals;

        Interval prev = intervals[0];
        for (int i=1; i<intervals.size(); i++) {
            if (prev.end < intervals[i].start) {
                rlt.push_back(prev);
                prev = intervals[i];
            }
            else {
                prev.end = max(prev.end, intervals[i].end);
            }
        }
        rlt.push_back(prev);
        return rlt;
    }
};

int main(int argc, char const *argv[])
{
	

	return 0;
}

