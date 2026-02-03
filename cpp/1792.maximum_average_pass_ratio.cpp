class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans=0;
        priority_queue<pair<double, int>, vector<pair<double, int>>> maxHeap;
        int size=classes.size();
        double a, b;
        for(int i=0; i<size; i++) {
            a=classes[i][0];
            b=classes[i][1];
            maxHeap.push({(b-a)/(b*(b+1)), i});
        }
        pair<double, int> top;
        while(extraStudents--) {
            top=maxHeap.top();
            maxHeap.pop();
            a=++classes[top.second][0];
            b=++classes[top.second][1];
            top.first=(b-a)/(b*(b+1));
            maxHeap.push(top);
        }
        for(int i=0; i<size; i++) {
            a=classes[i][0];
            b=classes[i][1];
            ans+=a/b;
        }
        return ans/size;
    }
};
