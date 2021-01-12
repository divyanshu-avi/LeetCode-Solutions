class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
			return "0";
		string ans = "";
		bool neg = (numerator < 0) != (denominator < 0);

		long long int num = numerator, den = denominator, rem, qt;
		num = abs(num); den = abs(den);

		if (neg)
			ans += "-";
		qt = num / den;
		ans += to_string(qt);
		rem = num % den;
		if (!rem)
			return ans;
		ans += ".";
		unordered_map<int, int> map;
		int i = ans.length();
		//If remainder becomes 0 stop. If same remainder is encountered again it means recurring.
		while (rem && map.find(rem) == map.end())
		{
			map.insert({rem, i++});//Store the index where to insert the '(' in case of recurring.
			num = rem * 10;
			qt = num / den;
			rem = num % den;
			ans += ('0' + qt);
		}
		if (!rem)
			return ans;
		i = map[rem];
		return ans.substr(0, i) + "(" + ans.substr(i) + ")";
	}
};