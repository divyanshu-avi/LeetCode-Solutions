class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size(), i = 0, j = n - 1;
		while (i < m && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target) //Go left to decrease value
				j--;
			else//Go down to increase value
				i++;
		}
		return false;
	}
};