#include<vector>
#include<algorithm>

using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

  bool myComp(const Interval &i1, const Interval &i2)
    {
        return i1.start < i2.start;
    }


    vector<Interval> merge(vector<Interval> &intervals) {

        if(intervals.size() == 0) return intervals;

        sort(intervals.begin(), intervals.end(), myComp);

        vector<Interval> ret;

        ret.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(ret[ret.size() - 1].end >= intervals[i].start)
            {
                if(ret[ret.size()-1].end < intervals[i].end)
                {
                    ret[ret.size()-1].end = intervals[i].end;
                }
            }else{
                ret.push_back(intervals[i]);
            }
        }

        return ret;

    }
