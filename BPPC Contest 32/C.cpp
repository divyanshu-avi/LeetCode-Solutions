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
	int n, i, cycle = 1, beg = 0;
	unsigned long long int x;
	cin >> n >> x;

	vector<int> arr(n);
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		arr[i]--;
		//cout << arr[i];
	}

	if (arr[0] == 0)
	{
		cout << 1;
		return;
	}

	int slow = 0, fast = arr[0];
	while (slow != fast)
	{
		slow = arr[slow];
		fast = arr[fast];
		fast = arr[fast];
	}
	fast = arr[fast];
	while (fast != slow)
	{
		cycle++;
		fast = arr[fast];
	}
	//Now I have length of cycle. Now lets find the head
	slow = fast = 0;
	for (i = 0; i < cycle; i++)
		fast = arr[fast];
	while (fast != slow && x > 0)
	{
		x--;
		fast = arr[fast];
		slow = arr[slow];
	}

	if (x == 0)
	{
		cout << slow + 1;
		return;
	}
	int rem = x % cycle;
	for (i = 0; i < rem; i++)
		fast = arr[fast];

	cout << fast + 1;


}