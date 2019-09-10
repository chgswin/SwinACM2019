#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 99;
int main()
{
  #ifndef ONLINE_JUDGE
    //freopen("1217C.in", "r", stdin);
  #endif

  int t;
  string s;
  cin >>t;
  while (t--)
  {
    cin >> s;
    int i;
    vector<int> maxOnePos(s.size(), -1);
    int n = s.size();
    //preprocess
    for (i = 0; i < n; ++i)
    {
      if (s[i] == '1') maxOnePos[i]=i;
      else maxOnePos[i]= i==0?-1:maxOnePos[i-1];
    }

    int r, l;
    int res = 0;
    for (r = 0; r < s.size(); ++r)
    {
      int sum = 0;
      for (l = r; l >= 0 && r - l <= 18; --l)
      {
        if (s[l] == '0') continue;
        sum += 1 << (r-l);
        if (sum <= r - (l==0 ? -1 : maxOnePos[l-1]))
          ++res;
      }
    }
    cout << res << endl;
  }
}
