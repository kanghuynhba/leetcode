class ExamTracker {
private:
    vector<int> timestamp;
    vector<long long> preSum;
public:
    ExamTracker() {
        preSum.push_back(0);
    }
    
    void record(int time, int score) {
        timestamp.push_back(time); 
        int size=preSum.size();
        preSum.push_back(preSum[size-1]+score);
    }
    
    long long totalScore(int startTime, int endTime) {
        int startId=lower_bound(timestamp.begin(), timestamp.end(), startTime)-timestamp.begin(); 
        int endId=lower_bound(timestamp.begin(), timestamp.end(), endTime)-timestamp.begin(); 
        if(endTime<timestamp[endId]) {
            endId--;
        }
        return preSum[endId+1]-preSum[startId];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
