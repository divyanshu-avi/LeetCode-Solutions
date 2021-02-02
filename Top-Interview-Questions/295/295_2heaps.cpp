class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int> > right;
	MedianFinder() {
		while (!left.empty())
			left.pop();
		while (!right.empty())
			right.pop();
	}

	void addNum(int num) {
		if (left.empty())
			left.push(num);
		else if (right.empty())
		{
			if (num < left.top())
			{
				left.push(num);
				num = left.top();
				left.pop();
			}
			right.push(num);
		}
		else if (left.size() == right.size())
		{
			if (num > right.top())
			{
				right.push(num);
				num = right.top();
				right.pop();
			}
			left.push(num);
		}
		else//left.size() > right.size()
		{
			if (num < left.top())
			{
				left.push(num);
				num = left.top();
				left.pop();
			}
			right.push(num);
		}
	}

	double findMedian() {
		if (left.size() == right.size())
			return (double)(left.top() + right.top()) / 2;
		else
			return left.top();
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */