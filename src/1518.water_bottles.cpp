class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int initEmpty=numBottles;
        int count=numBottles;
        while(numBottles>=numExchange) {
            count+=numBottles/numExchange;
            numBottles=numBottles/numExchange+numBottles%numExchange;
        }
        return count;
    }
};
