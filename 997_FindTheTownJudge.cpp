class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //truster: person who trusts other
        //trusted: person who is trusted by other
        //vector to store the number of people 
        vector<int> truster(N+1), trusted(N+1);
        int i;
        for (i = 0; i < trust.size(); ++i)
        {
            truster[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        int judge = 0;
        for (i = 1; i <= N; ++i)
        {
            if (truster[i] == 0 && trusted[i] == N - 1)
            {
                if (!judge)
                {
                    judge = i;
                }
                else 
                {
                    return -1;
                }
            }
        }
        return judge?judge:-1;
    }
};
