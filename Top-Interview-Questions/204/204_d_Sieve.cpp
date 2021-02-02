class Solution {
public:
	//Sieve of Eratosthenes
	int countPrimes(int n) {
		if (n < 2)
			return 0;
		int ans = 0;
		long long int i, j;
		vector<bool> done(n, 0);

		for (i = 2; i < n; i++)
			if (!done[i])
			{
				ans++;
				for (j = i * i; j < n ; j += i)
					done[j] = 1;
			}
		return ans;
	}
};