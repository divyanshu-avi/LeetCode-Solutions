#include<bits/stdc++.h>
using namespace std;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()
{
	int n, m, i, temp;
	unsigned long long int ans = 0;
	cin >> n >> m;
	vector<int> arr;
	priority_queue<int> pq;

	for (i = 0; i < n; i++)
	{
		cin >> temp;
		pq.push(temp);
	}
	while (m-- && !pq.empty())
	{
		temp = pq.top();
		temp = temp >> 1;
		pq.pop();
		if (temp)
			pq.push(temp);
	}
	while (!pq.empty())
	{
		ans += pq.top();
		//cout << pq.top() << ' ';
		pq.pop();
	}
	cout << ans;
}