class MedianFinder {
public:
    /** initialize your data structure here. */
    bool flag = true;
    priority_queue<int> mini;
    priority_queue<int,vector<int>,greater<int>> maxi;
    
    
    
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int top;
        
        if(flag){
            mini.push(num);
            top = mini.top();
            mini.pop();
            
            maxi.push(top);
            top = maxi.top();
            maxi.pop();
            
            mini.push(top);
            flag = false;
        }else{
            mini.push(num);
            top = mini.top();
            mini.pop();
            
            maxi.push(top);
            flag = true;
        }
        
    }
    
    double findMedian() {
        
        if(!flag){
            return (double)mini.top();
        }else{
            double d;
            d = mini.top();
            d+= (double)maxi.top();
            return d/2;
        }
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */