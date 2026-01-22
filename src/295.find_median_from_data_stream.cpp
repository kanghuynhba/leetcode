class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        bool flag=false;
        if(!maxHeap.empty() && num<maxHeap.top()) {
            flag=true;
            maxHeap.push(num); 
        }
        if(!minHeap.empty() && num>minHeap.top()) {
            flag=true;     
            minHeap.push(num);
        }
        if(!flag) {
            maxHeap.push(num);
        }
        if(maxHeap.size()-minHeap.size()==2) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size()-maxHeap.size()==2) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
   }
    
    double findMedian() {
        int diff=minHeap.size()-maxHeap.size();
        cout << diff << endl;
        if(diff==1) {
            return minHeap.top();
        } else if(diff==-1) {
            return maxHeap.top();
        }
        return (double)(minHeap.top()+maxHeap.top())/2;   
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
