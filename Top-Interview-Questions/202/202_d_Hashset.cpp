class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> hashset;
		int num;
		while (n != 1 && hashset.find(n) == hashset.end())
		{
			hashset.insert(n);
			num = 0;
			while (n)
			{
				num += (n % 10) * (n % 10);
				n /= 10;
			}
			n = num;
			//cout<<n<<'\n';
		}
		return n == 1;
	}
};