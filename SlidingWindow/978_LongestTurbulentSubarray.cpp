class Solution {
public:
    int compare(int a, int b)
    {
        if (a > b) return 1;
        else if (a == b) return 0;
        else return -1;
    }
    
    int maxTurbulenceSize(vector<int>& A) 
    {
        int n = A.size();
        //if (n == 1) return 1;
        
        int dp[n + 1];
        int sign[n + 1];
        sign[0] = 0;
        dp[0] = 1;        
        int i;
        int res = dp[0];
        for (i = 1; i < n; ++i)
        {
            sign[i] = compare(A[i], A[i-1]);
            
            if (!sign[i]) 
            {
                dp[i] = 1;
            }
            else if (sign[i-1] == sign[i])
            {
                dp[i] = 2;
            }
            else
            {
                dp[i] = dp[i-1] + 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
