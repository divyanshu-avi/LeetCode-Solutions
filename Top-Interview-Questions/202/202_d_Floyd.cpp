class Solution {
public:
	int digsqrsum(int n)
	{
		int ans = 0;
		while (n)
		{
			ans += (n % 10) * (n % 10);
			n /= 10;
		}
		return ans;

	}

	bool isHappy(int n) {
		unordered_set<int> hashset;
		int slow = n, fast = digsqrsum(n);
		while (fast != 1 && fast != slow)
		{
			fast = digsqrsum(digsqrsum(fast));
			slow = digsqrsum(slow);
		}
		return fast == 1;
	}
};