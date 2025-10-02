class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=numBottles, drunk=numBottles;
        while(empty>=numExchange) {
            drunk++;
            empty-=numExchange;
            numExchange++;
            empty++;
        }
        return drunk;
    }
};
