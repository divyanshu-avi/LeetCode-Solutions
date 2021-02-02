class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> map;
		int i, n = nums.size();

		for (i = 0; i < n; i++)
			map[nums[i]]--;

		priority_queue<pair<int, int>> pq;
		for (auto it = map.begin(); it != map.end(); it++)
		{
			pq.push({it->second, it->first});
			if (pq.size() > k)
				pq.pop();
		}
		vector<int> ans;
		while (!pq.empty())
		{
			ans.push_back(pq.top().second);
			//cout<<pq.top().first;
			pq.pop();
		}
		return ans;
	}
};