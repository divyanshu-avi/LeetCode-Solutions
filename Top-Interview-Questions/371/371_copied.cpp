class Solution {
public:

	int getSum(int a, int b) {
		unsigned int carry, x = a, y = b;
		while (y != 0)
		{
			carry = (x & y) << 1;
			x = x ^ y; //This is the sum
			y = carry;
		}
		return x;
	}
};