// Time complexity: O(n) on average. Slight variation due to unordered_map worst case: O(n) each insertion.
// Space complextiy: O(n): on another map.

class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int res = 0;
        unordered_map<int, int> difference;
        int i;
        int n = nums.size();
        int num1 = 0, num0 = 0;
        difference[0] = -1;
        for (i = 0; i < n; ++i)
        {
            if (nums[i]) num1++; else num0++;
            
            if (!difference.count(num1-num0))
            {
                difference[num1 - num0] = i;
            }
            else
            {
                res = max(res, i - difference[num1-num0]);
            }
        }
        return res;
    }
};
