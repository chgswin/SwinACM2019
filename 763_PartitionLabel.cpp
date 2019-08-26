class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size();
        int i, j;
        i = 0;
        //two maps to store the left_bound and the right_bound
        unordered_map<int, int> start, end;
        for (i = 0; i < n; ++i)
        {
            if (start.find(S[i]) == start.end())
            {
                start[S[i]] = i;
            }
            else
            {
                end[S[i]] = i;
            }
        }
        i = 0;
        vector<int> result;
        while (i < n)
        {
            int left = i;
            int right = (end.find(S[i]) == end.end()) ? i : end[S[i]];
            j = ++i;
            while (i < n && i < right)
            {
                if (end.find(S[i]) != end.end() && end[S[i]] > right)
                {
                    right = end[S[i]];
                }
                ++i;
            }
            result.push_back(right - left + 1);
            i = right + 1;
        }
        return result;
    }
};
