class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = 0;
        int empty = 0;
        int exchange = numExchange;
        
        while (numBottles > 0) {
            total++;
            numBottles--;
            empty++;
            
            while (empty >= exchange) {
                empty -= exchange;
                numBottles++;
                exchange++;
            }
        }
        
        return total;
    }
};