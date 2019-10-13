#include <bits/stdc++.h>

using namespace std;

int count1(string & s)
{
	int result = 0;
	for (char a: s)
	{
		if (a == '1') result ++;
	}
	return result;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("1244B.in", "r", stdin);
	#endif

	int t, n;
	string binary;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cin >> binary;
		int n1 = count1(binary);

		int result = n + n1;

		for (int i = 0; i < binary.size(); ++i)
		{
			if (binary[i] == '1')
			{
				result = max(result, (i+1)*2);
				result = max(result, (n-i)*2);
			}
		}
		cout << result << endl;
	}
	return 0;

}
