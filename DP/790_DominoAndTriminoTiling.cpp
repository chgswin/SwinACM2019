class Solution {

const int MOD = 1e9 + 7;
int up[1001];
int full[1001];
int down[1001];

int add(int a, int b)
{
    long long sum = 0LL + a + b;
    return sum%MOD;
}

public:    
    int numTilings(int N) {
        full[0]=full[1]=1;
        up[0]=up[1]=0;
        down[0]=down[1]=0;
        int i;
        for (i = 2; i <= N; ++i)
        {
            up[i]=add(full[i-2], down[i-1]);
            down[i]=add(up[i-1], full[i-2]);
            full[i] = add(full[i-1],full[i-2]);
            full[i] = add(full[i], up[i-1]);
            full[i] = add(full[i], down[i-1]);
        }
        return full[N];
    }
};
