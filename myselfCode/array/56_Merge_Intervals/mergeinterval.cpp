#include "../leetcodeutil.h"

class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
    if (ins.empty()) return vector<Interval>{};
    vector<Interval> res;
    sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
    res.push_back(ins[0]);
    for (int i = 1; i < ins.size(); i++) {
        if (res.back().end < ins[i].start) res.push_back(ins[i]);
        else
            res.back().end = max(res.back().end, ins[i].end);
    }
    return res;
}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return intervals;
        std::sort(intervals.begin(), intervals.end(), [](const Interval& I1, const Interval& I2)->bool
        {
            return I1.start < I2.start;
        });
        
        vector<Interval> new_intervals;
        Interval curr_int = intervals[0];
        for(const auto& i : intervals)
        {
            if(i.start <= curr_int.end)
            {
                curr_int.end = std::max(i.end, curr_int.end);
            }
            else
            {
                new_intervals.push_back(curr_int);
                curr_int = i;
            }
        }
        new_intervals.push_back(curr_int);
        return new_intervals;
    }
};

int main(int argc, char const *argv[])
{
  

  return 0;
}
