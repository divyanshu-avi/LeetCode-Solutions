class Solution {
public:
	//"Heavily" inspired by someone's code in the discussion forum
	//Changed a few things for my better understanding
	vector<vector<int>> getSkyline(vector<vector<int>>& bgs) {
		int i = 0, n = bgs.size(), pos, height;
		priority_queue<pair<int, int>> pq;
		vector<vector<int>> ans;

		while (i < n) //if i is valid or we still have some buildings left inside pq
		{
			if (!pq.empty()) //pq.top().seond needs to be stored b4 going inside while because at this point height might change (reduce).
				pos = pq.top().second;
			if (!pq.empty() && pq.top().second < bgs[i][0]) //If there is a gap
			{
				while (!pq.empty() && pq.top().second <= pos) //If there is a gap
					pq.pop();//Trying to find a smaller building to fill the gap
			}
			else
			{
				pos = bgs[i][0];//current position is the left edge of new building
				while (i < n && bgs[i][0] == pos) //Multiple buildings could start at pos
				{
					pq.push({bgs[i][2], bgs[i][1]});
					i++;
				}
			}
			height = pq.empty() ? 0 : pq.top().first;
			//If pq is empty means we were not able to fill the gap, so height = 0
			if (ans.empty() || ans.back()[1] != height) //Only push if there's a change in the height
				ans.push_back({pos, height});

		}
		//Now we have pushed all buildings into the pq
		while (!pq.empty())
		{
			pos = pq.top().second;
			pq.pop();
			while (!pq.empty() && pq.top().second <= pos)
				pq.pop();
			height = pq.empty() ? 0 : pq.top().first;//If this was the last building, height = 0
			if (ans.empty() || ans.back()[1] != height) //Only push if there's a change in the height
				ans.push_back({pos, height});
		}
		return ans;
	}
};