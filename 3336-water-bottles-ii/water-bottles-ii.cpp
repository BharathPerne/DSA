class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        
        while (numBottles-numExchange>=0) {
            int full_bottles = 0;
            while (numBottles - numExchange >= 0) {               
                numBottles = numBottles - numExchange;
                full_bottles++;
                numExchange++;
            }
            ans += full_bottles;
            numBottles = numBottles+full_bottles;
        }
        return ans;
    }
};