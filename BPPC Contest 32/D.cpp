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

void visit(int city, long long int val, vector<bool>&visited, vector<vector<int>>& adj, vector<long long int>& def)
{
	visited[city] = 1;
	def[city] += val;
	int i;
	for (i = 0; i < adj[city].size(); i++)
		if (!visited[adj[city][i]])
			visit(adj[city][i], def[city], visited, adj, def);

}

void solve()
{
	int n, q, i, a, b;
	cin >> n >> q;
	vector<long long int> def(n + 1, 0);
	vector<vector<int>> adj(n + 1, vector<int>());
	vector<bool> visited(n + 1, 0);

	for (i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (i = 0; i < q; i++)
	{
		cin >> a >> b;
		def[a] += b;
	}

	for (i = 1; i <= n; i++)
		if (!visited[i])
			visit(i, 0, visited, adj, def);

	for (i = 1; i <= n; i++)
		cout << def[i] << ' ';

}