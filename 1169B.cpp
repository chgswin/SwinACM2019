#include<bits/stdc++.h>
//#include<unordered_set>

using namespace std;

int n, m, a, b;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("1169B.in", "r", stdin);
	#endif

	int count = 0;
	int max_value = 0;
	int max_index = 0;

	cin >> n >> m;

	vector< unordered_set<int> > adj;
	unordered_set< int > reduced_list;
	adj.resize(n+1);

	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		if (!adj[a].count(b))
		{
			reduced_list.insert(a);
			reduced_list.insert(b);
			adj[a].insert(b);
			adj[b].insert(a);
			++count;
			int local_max = max(adj[a].size(), adj[b].size());
			if (local_max >= max_value)
			{
				max_value = local_max;
				max_index = (adj[a].size()==local_max)?a:b;
			}
		}
	}

	int temp = count - max_value;

	while (temp > 0 && temp <= max_value)
	{
		unordered_set< int > temp_list;
		int temp_max_index = max_index;
		max_value = 0;
		max_index = 0;
		for (const int & index : reduced_list)
		{
			if (adj[index].size() - adj[index].count(temp_max_index) >= temp && index != temp_max_index)
			{
				temp = 0;
				break;
			}
			else if (adj[index].size() >= temp && index != temp_max_index)
			{
				temp_list.insert(index);
				if (adj[index].size() >= max_value)
				{
					max_value = adj[index].size();
					max_index = index;
				}
			}
		}
		if (temp != 0)
		{
			if (!temp_list.size())
				temp = 1;
			else
			{
				temp = count - max_value;
				reduced_list.clear();
				reduced_list = temp_list;
			}
		}
	}
	
	if (temp <= 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}