class Solution {
public:
	int add(int x, int y, int z, int& sum)
	{
		sum = (x ^ y ^ z);
		int carry;
		if (sum)
			carry = (x & y & z);
		else
			carry = (x | y | z);
		return carry;
	}

	int getSum(int a, int b) {
		int ans = 0, i, x, y, temp;
		bool carry = 0, prev = 0;
		for (i = 0; i < 32; i++)
		{
			x = a & 1;
			y = b & 1;
			a >>= 1;
			b >>= 1;
			prev = add(x, y, prev, temp);
			ans |= temp << i;
		}
		return ans;
	}
};