class Solution {
public:
    double min(double a, double b) {
        if(a<b) {
            return a;
        }
        return b;
    }
    double max(double a, double b) {
        if(a>b) {
            return a;
        }
        return b;
    }
    bool calcBelowLine(vector<vector<int>>& squares, double total, double y) {
        double below=0;
        for(int i=0; i<squares.size(); i++) {
            if(squares[i][1]<=y && y<=squares[i][1]+squares[i][2]) {
                below+=(y-squares[i][1])*squares[i][2]; 
            } else if(squares[i][1]+squares[i][2]<y) {
                below+=pow(squares[i][2], 2); 
            }
        }
        return below>=total/2;
    }
    double binarySearch(vector<vector<int>>& squares, double total,
            double left, double right) {
        double ans;
        while(left<right) {
            double mid=left+(right-left)/2;
            if(calcBelowLine(squares, total, mid)) {
                right=mid-0.000001;
            } else {
                ans=mid;
                left=mid+0.000001;
            }
        }
        return ans;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double minY=INT_MAX, maxY=INT_MIN;
        double total=0;
        for(int i=0; i<squares.size(); i++) {
            minY=min(minY, squares[i][1]);
            maxY=max(maxY, squares[i][1]+squares[i][2]);
            total+=pow(squares[i][2], 2);
        }
        return binarySearch(squares, total, minY, maxY);
    }
};
