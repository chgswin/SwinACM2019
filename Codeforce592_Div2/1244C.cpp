#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("1244C.in", "r", stdin);
	#endif

	long long n, p, w, d;

	cin >> n >> p >> w >> d;

	long long x, y, z;
	if (p % __gcd(w,d))
	{
		cout << -1 << endl;
		return 0;
	}

	long long x0, y0;
	for (x = 0; x < d; ++x)
	{
		long long dy = p - w*x;
		if (dy < 0) 
		{
			cout << -1 << endl;
			return 0;
		}
		if (dy % d == 0)
		{
			x0 = x;
			y0 = dy / d;
			break; 
		}
	}

	long long gcd = __gcd(w,d);

	if (x0 + y0 <= n)
	{
		cout << x0 << " " << y0 << " " << n - x0 - y0 << endl;
	}
	else
	{
		long long prod = 1LL * gcd * (x0 + y0 - n);
		long long tmin = (prod-1)/(w-d) + 1;

		x = x0 + d/gcd * tmin;
		y = y0 - w/gcd * tmin;
		if (y >= 0 && x + y <= n)
		{
			cout << x << " " << y << " "<< n - x- y << endl;
		} 
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
