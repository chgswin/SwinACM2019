#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("1234B2.in", "r", stdin);
	#endif

	int n, k;

	vector<int> message;

	cin >> n >> k;

	queue<int> notification;

	set<int> save;

	message.resize(n);

	int i;

	for (i = 0; i < n; ++i)
	{
		cin >> message[i];
		if (save.count(message[i]) == 0)
		{
			save.insert(message[i]);
			notification.push(message[i]);
		}
		
		if (notification.size() > k)
		{
			int frontId = notification.front();
			save.erase(frontId);
			notification.pop();		
		}
	}

	cout << notification.size() << endl;
	stack<int> result;
	
	while (!notification.empty())
	{
		result.push(notification.front());
		notification.pop();
	}
	
	while (!result.empty())
	{
		printf("%d ", result.top());
		result.pop();
	}
	return 0;
}
