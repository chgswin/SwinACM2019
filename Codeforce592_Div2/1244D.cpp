#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[111111];

int cost[4][111111];

long long result = 1e18; 

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("1244D.in", "r", stdin);
	#endif

	int n, i, a, b;
	cin >> n;
	for (int c = 1; c <= 3; ++c)
	{
		for (i = 1; i <= n; ++i)
		{
			cin >> cost[c][i];
		}
	}

	for (i = 1; i < n; ++i)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].pb(a);
	}

	int root;
	for (i = 1; i <= n; ++i)
	{
		//cout << i << " " << adj[i].size() << endl;
		if (adj[i].size() == 1)
		{
			root = i;
		}
		else if (adj[i].size() > 2)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> group[3];

	group[0].pb(root);

	int index = 0;
	int curNode = adj[root][0];
	//cout << curNode << endl;
	while (adj[curNode].size() != 1)
	{
		//cout << root << " " << adj[curNode][1] << endl;
		++index;
		group[index % 3].pb(curNode);
		for (i = 0; i < adj[curNode].size(); ++i)
		{
			if (adj[curNode][i] == root)
			{
				continue;
			}
			else
			{
				root = curNode;
				curNode = adj[curNode][i];
				break;
			}
		}
	}
	group[++index % 3].pb(curNode);
//	int t = 0;
	// for (i = 0; i < group[t].size(); ++i)
	// {
	// 	cout << group[t][i] << " ";
	// }
	int s1,s2,s3;
	int s1s, s2s, s3s;	
	for (s1 = 1; s1 <= 3; s1++)
	{
		for (s2 = 1; s2 <= 3; ++s2)
		{
			long long temp = 0LL;
			if (s1 == s2) continue;
			
			for (i = 0; i < group[0].size(); ++i)
			{
				temp+=cost[s1][group[0][i]];
			}
			for (i = 0; i < group[1].size(); ++i)
			{
				temp+=cost[s2][group[1][i]];
			}
			for (i = 0; i < group[2].size(); ++i)
			{
				temp+=cost[6 - s1 - s2][group[2][i]];
			}
			if (temp < result)
			{
				result = temp;
				s1s = s1;
				s2s = s2;
				s3s = 6 - s1 - s2;
			}
		}
	}

	vector<int> array;
	array.resize(n + 1);

	for (i = 0; i < group[0].size(); ++i)
	{
		array[group[0][i]] = s1s;
	}
	for (i = 0; i < group[1].size(); ++i)
	{
		array[group[1][i]] = s2s;
	}
	for (i = 0; i < group[2].size(); ++i)
	{
		array[group[2][i]] = s3s;
	}

	cout << result << endl;
	for (i = 1; i <= n; ++i)
	{
		cout << array[i] << " ";
	}
	return 0;
}

