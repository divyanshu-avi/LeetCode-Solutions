/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
	vector<int> ans;
	int itr, sz;
	NestedIterator(vector<NestedInteger> &nestedList) {
		itr = 0;
		build(ans, nestedList);
		sz = ans.size();
	}
	void build(vector<int>& ans, vector<NestedInteger> &List)
	{
		int i, n = List.size();
		for (i = 0; i < n; i++)
		{
			if (List[i].isInteger())
				ans.push_back(List[i].getInteger());
			else
				build(ans, List[i].getList());
		}
	}

	int next() {
		return ans[itr++];
	}

	bool hasNext() {
		return itr < sz;
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */