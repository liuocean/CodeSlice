/*
Merge Intervals 

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include<iostream>
#include<vector>

using namespace std;

typedef struct Interval{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s, int e): start(s), end(e){}
}Interval;

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
		if(intervals.empty())
			return res;
		Interval temp;
		
		temp.start=intervals[0].start, temp.end=intervals[0].end;
		for(size_t i=1; i<intervals.size(); i++){
			if(intervals[i].start > temp.end){
				res.push_back(temp);
				temp.start=intervals[i].start;
				temp.end=intervals[i].end;
			}
			else if(intervals[i].end > temp.end){
				temp.end=intervals[i].end;
			}
		}
		res.push_back(temp);
		
		return res;
    }
	
	int cmp(const struct Interval &lhs, const struct Interval &rhs){
		return lhs.start < rhs.start;
	}
};

int main(){
	Solution solution;
	vector<Interval>intervals, res;
	Interval array[]={{1,3}, {2, 6}, {8, 10}, {15, 18}};
	// intervals.push_back(Interval temp(1, 3));
	// intervals.push_back(Interval temp(2, 6));
	// intervals.push_back(Interval temp(8, 10));
	// intervals.push_back(Interval temp(15, 18));
	intervals.insert(intervals.begin(), array, array+sizeof(array)/sizeof(Interval));
	res=solution.merge(intervals);
	for(size_t i=0; i<res.size(); i++){
		cout<<res[i].start<<" "<<res[i].end<<endl;
	}
	
	return 0;
}

