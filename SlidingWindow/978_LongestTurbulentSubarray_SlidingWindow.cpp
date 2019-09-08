class Solution {
public:
    //return 1 when positive
    //return 0 when 0
    //return -1 when negative
    int sign(int a)
    {
        return (a > 0) - (a < 0);
    }
    
    int maxTurbulenceSize(vector<int>& A) 
    {
        int n = A.size();
        int left = 0;
        int right = 1;
        int curSign = 0;
        int res = 1;
        while (right  < n)
        {
            int justSign = sign(A[right] - A[right - 1]);
            if (justSign == 0)
            {
                left = right;
            }
            else if (justSign == curSign)
            {
                 left = right - 1;   
            }
            curSign = justSign;
    
            ++right;
            res = max(res, right - left);
            
        }
        
        return res;
    }
};
