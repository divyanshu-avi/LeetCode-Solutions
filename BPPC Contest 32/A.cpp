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
	int n, i, jor = 0;
	cin >> n;

	vector<int> arr(n);
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		jor = jor ^ arr[i];
	}
	for (i = 0; i < n; i++)
		cout << (jor ^ arr[i]) << ' ';
}