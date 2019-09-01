bool Compare(vector<int> const & v1, vector<int > const & v2)
{
        if (v1[0] == v2[0]) return v1[1] < v2[1];
        else return v1[0] < v2[0];
}

class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), Compare);
        
        vector< vector<int> > result;
        int i = 0;
        int n = intervals.size();
        
        while (i < n)
        {
            vector<int> temp = intervals[i];
            int curIndex = i + 1;
            
            while (curIndex < n)
            {
                if (intervals[curIndex][0] > temp[1]) break;
                else {
                    temp[1] = max(temp[1], intervals[curIndex][1]);
                }
                ++curIndex;
            }
            
            result.push_back(temp);
            i = curIndex;
        }
        return result;
        
    }
};
